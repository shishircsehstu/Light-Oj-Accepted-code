#include<stdio.h>
#include<string.h>
int main()
{
    char str1[20],str2[20],str3[20],str4[20],str5[20],s1[20],s2[20],s3[20],s4[20];
    long int a,b,c,d,e,f,g,h,i,w,r,n,j,t;
    scanf("%ld",&t);
    for(j=1; j<=t; j++)
    {
        scanf("%ld.%ld.%ld.%ld",&a,&b,&c,&d);
        r=0;
        if(a==0)
        {
            strcpy(str1,"0");
        }
        else
        {
            while(a>0)
            {
                str5[r]=a%2+'0';
                a/=2;
                r++;
            }
            w=0;
            for(i=r-1; i>=0; i--)
            {
                str1[w]=str5[i];
                w++;
            }
            str1[w]='\0';
        }
        if(b==0)
        {
            strcpy(str2,"0");
        }
        else
        {
            r=0;
            while(b>0)
            {
                str5[r]=b%2+'0';
                b/=2;
                r++;
            }
            w=0;
            for(i=r-1; i>=0; i--)
            {
                str2[w]=str5[i];
                w++;
            }
            str2[w]='\0';
        }
        if(c==0)
        {
            strcpy(str3,"0");
        }
        else
        {
            r=0;
            while(c>0)
            {
                str5[r]=c%2+'0';
                c/=2;
                r++;
            }
            w=0;
            for(i=r-1; i>=0; i--)
            {
                str3[w]=str5[i];
                w++;
            }
            str3[w]='\0';
        }
        if(d==0)
        {
            strcpy(str4,"0");
        }
        else
        {
            r=0;
            while(d>0)
            {
                str5[r]=d%2+'0';
                d/=2;
                r++;
            }
            w=0;
            for(i=r-1; i>=0; i--)
            {
                str4[w]=str5[i];
                w++;
            }
            str4[w]='\0';
        }
        scanf("%ld.%ld.%ld.%ld",&e,&f,&g,&h);
        if(e==0)
            strcpy(s1,"0");
        else
            sprintf(s1,"%ld",e);
        if(f==0)
            strcpy(s2,"0");
        else
            sprintf(s2,"%ld",f);
        if(g==0)
            strcpy(s3,"0");
        else
            sprintf(s3,"%ld",g);
        if(h==0)
            strcpy(s4,"0");
        else
            sprintf(s4,"%ld",h);
        if(strcmp(str1,s1)==0&&strcmp(str2,s2)==0&&strcmp(str3,s3)==0&&strcmp(str4,s4)==0)
            printf("Case %ld: Yes\n",j);
        else
            printf("Case %ld: No\n",j);
    }
 
}
 
