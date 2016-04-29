// test against iptables v1.4.21
// compiled by gcc -o iptables_disable_port iptables_disable_port.c -lip4tc

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/errno.h>
#include "libiptc/libiptc.h"
#include "linux/netfilter/xt_limit.h"
#include "linux/netfilter/xt_physdev.h"
#include "linux/netfilter/xt_time.h"
#include "iptables.h"
#include <netinet/in.h>



int main(void)
{
    int ret;
    struct xtc_handle *h;

    const xt_chainlabel chain = "INPUT";
    const char * tablename = "filter";

    struct ipt_entry * e;
    struct ipt_entry_match * match_proto, * match_limit, * match_physdev;


    struct ipt_entry_target *target;
    struct ipt_tcp * tcpinfo;

    // time limit
    struct xt_time_info *timelimit;

    struct xt_physdev_info * physdevinfo;
    unsigned int size_ipt_entry, size_ipt_entry_match, size_ipt_entry_target, size_ipt_tcp, size_timelimit, size_physdevinfo, total_length;

    size_ipt_entry = XT_ALIGN(sizeof(struct ipt_entry));
    size_ipt_entry_match = XT_ALIGN(sizeof(struct ipt_entry_match));
    size_ipt_entry_target = 40;//XT_ALIGN(sizeof(struct ipt_entry_target)); I don't know why the XT_ALIGN() does not work in this case, may be 36 is 42 in netfilter :)


    size_ipt_tcp = XT_ALIGN(sizeof(struct ipt_tcp));
    size_timelimit = XT_ALIGN(sizeof(struct xt_time_info));
    size_physdevinfo = XT_ALIGN(sizeof(struct xt_physdev_info));
    total_length =  size_ipt_entry + size_ipt_entry_match * 3 + size_ipt_entry_target + size_ipt_tcp + size_timelimit + size_physdevinfo;
    //total_length =  size_ipt_entry + size_ipt_entry_match * 2 + size_ipt_entry_target + size_ipt_tcp + size_physdevinfo;

    //memory allocation for all structs that represent the netfilter rule we want to insert
    e = (struct ipt_entry *)calloc(1, total_length);
    if(e == NULL)
    {
        printf("malloc failure");
        exit(1);
    }

    //offsets to the other bits:
    //target struct begining
    e->target_offset = size_ipt_entry + size_ipt_entry_match * 3 + size_ipt_tcp + size_timelimit + size_physdevinfo;
    e->next_offset = total_length;

    //set up packet matching rules: “-s 156.145.1.3 -d 168.220.1.9 -i eth0” part
    //of our desirable rule
    //e->ip.src.s_addr = inet_addr("156.145.1.3");
    //e->ip.smsk.s_addr= inet_addr("255.255.255.255");
    e->ip.dst.s_addr = inet_addr("168.220.1.9");
    e->ip.dmsk.s_addr= inet_addr("255.255.255.255");
    e->ip.proto = IPPROTO_TCP;
    e->nfcache = 0;
    strcpy(e->ip.iniface, "eth0");

    //match structs setting:
    //set match rule for the protocol to use
    //”-p tcp” part of our desirable rule
    match_proto = (struct ipt_entry_match *) e->elems;
    match_proto->u.match_size = size_ipt_entry_match + size_ipt_tcp;
    strcpy(match_proto->u.user.name, "tcp");



    //”-m time” part of our desirable rule
    match_limit = (struct ipt_entry_match *) (e->elems + match_proto->u.match_size);
    match_limit->u.match_size = size_ipt_entry_match + size_timelimit;
    strcpy(match_limit->u.user.name, "time");


    //set match rule for specific Ethernet card (interface)
    //”-m physdev” part of our desirable rule
    match_physdev = (struct ipt_entry_match *) (e->elems + match_proto->u.match_size + match_limit->u.match_size);
    match_physdev->u.match_size = size_ipt_entry_match + size_physdevinfo;
    strcpy(match_physdev->u.user.name, "physdev");//set name of the module, we will use in this match

    //tcp module - match extension
    //”--dport 22” part of our desirable rule
    tcpinfo = (struct ipt_tcp *)match_proto->data;
    tcpinfo->spts[0] = 0x0;
    tcpinfo->spts[1] = 0xFFFF;
    tcpinfo->dpts[0] = 22;
    tcpinfo->dpts[1] = 22;


    timelimit = (struct xt_time_info *)match_limit->data;
    timelimit->weekdays_match = 0xFE;  // all weekdays
    timelimit->daytime_start = 9 * 60 * 60; // count by second
    timelimit->daytime_stop = 19 * 60 * 60;


    //physdev module - match extension
    //”-in eth0” part of our desirable rule
    physdevinfo = (struct xt_physdev_info *)match_physdev->data;
    strcpy(physdevinfo->physindev, "eth0");
    memset(physdevinfo->in_mask, 0xFF, IFNAMSIZ);
    physdevinfo->bitmask = 1;

    //target struct
    //”-j ACCEPT” part of our desirable rule
    target = (struct ipt_entry_target *)(e->elems + size_ipt_entry_match * 3 + size_ipt_tcp + size_timelimit + size_physdevinfo);
    target->u.target_size = size_ipt_entry_target;
    strcpy(target->u.user.name, "ACCEPT");


    //All the functions, mentioned below could be found in "Querying libiptc HOWTO" manual

    h = iptc_init(tablename);
    if(!h)
    {
        printf("Error initializing: %s\n", iptc_strerror(errno));
        exit(errno);
    }


    ret = iptc_append_entry("INPUT", e, h);
    if(!ret)
    {
        printf("Error append_entry: %s\n", iptc_strerror(errno));
        exit(errno);
    }


    printf("aaa %s", target->data);
    ret = iptc_commit(h);
    if(!ret)
    {
        printf("Error commit: %s\n", iptc_strerror(errno));
        exit(errno);
    }

    exit(0);
}
