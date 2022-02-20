#include<iostream>  
#include<string>  
#include<cstdio>  
using namespace std;  
  
int main()  
{  
    string a,b;  
    int num,sum[1000];//数组尽量开大点，不然很容易越界！  
    cin>>num;  
    for(int l=0;l<num;l++)  
    {  
        cin>>a>>b;  
        int m=0,n=0,temp=0,i,k;  
        int q=0;//用于记录sum数组的长度！！  
        i=a.length();  
        k=b.length();  
        //for(i=0;a[i]!='\0';i++);  
    //for(k=0;b[k]!='\0';k++);  
        i=i-1;  
        k=k-1;  
       // cout<<"刚开始时 i="<<i<<"  "<<"k="<<k<<endl;  
        while(i>=0 && k>=0)//像是这样加，会一直加到一个数加完  
        {  
            m=a[i]- '0';  
        //  cout<<"m="<<m<<" ";  
            n=b[k]-'0';  
        //  cout<<"n="<<n<<endl;  
          
            sum[q++]=(temp+m+n)%10;  
        //  cout<<"sum[q-1]="<<sum[q-1]<<endl;  
            temp=(temp+m+n)/10;//temp取进位，并且加到下一次的加法中  
            //cout<<"temp="<<temp<<endl;  
        //  cout<<"q="<<q<<endl;  
            i--;  
            k--;  
        //  cout<<"i="<<i<<" "<<"k="<<k<<endl;  
        //  cout<<endl;  
        }  
        //还需要处理一个长度的问题，判断哪个长，哪个短！  
      if(i>k)//a数比较大，确切的说是比较长！  
      {//cout<<"I am 1"<<endl;  
          while(i>=0)  
          {  
               
             m=a[i]-'0';  
             sum[q++]=(temp+m)%10;  
             temp=(temp+m)/10;//坑爹的坑，在这里坑了一次，我本来是temp+m+n，然后不知为何错了，很难察觉的！  
  
             i--;  
          }  
      }  
      if(k>i)  
      {  
         // cout<<"I am 2"<<endl;  
        // cout<<"k="<<k<<" "<<"temp="<<temp<<endl;  
         while(k>=0)  
          {  
             m=b[k]-'0';//这里也被坑了一次，我把b写成了a，全是复制粘贴惹的祸  
            //cout<<"m="<<m<<endl;  
             sum[q++]=(temp+m)%10;  
            //cout<<"sum[q-1]="<<sum[q-1]<<endl;  
             temp=(temp+m)/10;  
             k--;  
          }  
      }  
      sum[q]=temp;  
     // for(i=50;;i--)  
         // if(sum[i]!=0)  
        //    break;  
          //for(i++;i>=0;i--)  
      cout<<"Case "<<l+1<<":"<<endl;  
     cout<<a<<" + "<<b<<" = ";  
      if(sum[q]!=0) cout<<sum[q];  
          for(--q;q>=0;q--)  
          cout<<sum[q];  
     //printf("%d",sum[--q]);//第一个测试数据成功！  
    // for(--q;q>=0;q--)  
    // {  
    //   printf("%04d",sum[q]);  
    // }  
     cout<<endl;  
     if(l<num-1) cout<<endl;  
  
    }//for  
return 0;
}  

