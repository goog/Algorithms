/*
 * tier.cxx
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * 
 * 
 */


using namespace std;
#include <iostream>
#include <cstring>
#define NUM 26


class Node
{
public:
    int count;  // occurrence times
    Node *alphas[NUM];
    char *current_str;// until the node , the complete string;
    Node();
    ~Node();
};

Node::Node()
{
    count = 0;
    for(int i = 0; i < NUM; i++)
        alphas[i] = NULL;
    current_str = new char[100];
    current_str[0] = '\0';
}
 
 
Node::~Node()
{
    delete current_str;
    current_str = NULL;
}
 


class Trie
{
public:
    Node* root;
    Trie();
    void insert(const char* str);
    void output(const Node* const node, char** str, int& count);
};

Trie::Trie()
{
    root =  new Node();
}


void Trie::insert(const char *str)
{
    Node *p = root;
    if (str && str[0] == '\0')  return;
    const char *s = str;
    
    for(;*s;s++)
    {
        if(p->alphas[*s-'a']== NULL)
            p->alphas[*s-'a'] = new Node();
        p = p->alphas[*s-'a']; // current node
    }
    
    if( p->current_str[0] == '\0')
        strcpy(p->current_str,str);/// mistake str for s
    p->count++;
}

//
void Trie::output(const Node* const node, char** str, int& count)
{   
    if(node == NULL) return;
	
		
    if(node->count != 0)
    {
        for(int i = 0; i < node->count; i++)
            str[count++] = node->current_str;
    }
    
  
	for(int i = 0; i < NUM; i++)
	{
		if(node->alphas[i] != NULL)
			output(node->alphas[i], str, count);
	}

 
}


int main()
{
    char** str = new char*[12];
    str[0] = (char*)"zbdfasd";
    str[1] = (char*)"zbcfd";
    str[2] = (char*)"zbcdfdasfasf";
    str[3] = (char*)"abcdaf";
    str[4] = (char*)"defdasfa";
    str[5] = (char*)"fedfasfd";
    str[6] = (char*)"dfdfsa";
    str[7] = (char*)"dadfd";
    str[8] = (char*)"dfdfasf";
    str[9] = (char*)"abcfdfa";
    str[10] = (char*)"fbcdfd";
    str[11] = (char*)"abcdaf";
    
    Trie* trie = new Trie();
    for(int i = 0; i < 12; i++)
        trie->insert(str[i]);

    int count = 0;
    trie->output(trie->root, str, count);
 
    for(int i = 0; i < 12; i++)
        cout<<str[i]<<endl;

    return 0;
}

