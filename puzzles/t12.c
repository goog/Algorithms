

void duff(register char *to, register char *from, register int count)
{
      register int n=(count+7)/8;
      switch(count%8){
      case 0: do{ *to++ = *from++;
      case 7:  *to++ = *from++;
      case 6: *to++ = *from++;
      case 5: *to++ = *from++;
      case 4: *to++ = *from++;
      case 3: *to++ = *from++;
      case 2: *to++ = *from++;
      case 1: *to++ = *from++;
              }while( --n >0);
      }
}



int main()
{

    char aa[9] = "abcdefgh";
    char bb[9] = "";
    duff(aa, bb, 8);

    printf("the bb is %s.\n", bb);

}
