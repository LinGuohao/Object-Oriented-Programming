#include<iostream>  
#include<string>  
#include<cstdio>  
using namespace std;  
  
int main()  
{  
    string a,b;  
    int num,sum[1000];//���龡������㣬��Ȼ������Խ�磡  
    cin>>num;  
    for(int l=0;l<num;l++)  
    {  
        cin>>a>>b;  
        int m=0,n=0,temp=0,i,k;  
        int q=0;//���ڼ�¼sum����ĳ��ȣ���  
        i=a.length();  
        k=b.length();  
        //for(i=0;a[i]!='\0';i++);  
    //for(k=0;b[k]!='\0';k++);  
        i=i-1;  
        k=k-1;  
       // cout<<"�տ�ʼʱ i="<<i<<"  "<<"k="<<k<<endl;  
        while(i>=0 && k>=0)//���������ӣ���һֱ�ӵ�һ��������  
        {  
            m=a[i]- '0';  
        //  cout<<"m="<<m<<" ";  
            n=b[k]-'0';  
        //  cout<<"n="<<n<<endl;  
          
            sum[q++]=(temp+m+n)%10;  
        //  cout<<"sum[q-1]="<<sum[q-1]<<endl;  
            temp=(temp+m+n)/10;//tempȡ��λ�����Ҽӵ���һ�εļӷ���  
            //cout<<"temp="<<temp<<endl;  
        //  cout<<"q="<<q<<endl;  
            i--;  
            k--;  
        //  cout<<"i="<<i<<" "<<"k="<<k<<endl;  
        //  cout<<endl;  
        }  
        //����Ҫ����һ�����ȵ����⣬�ж��ĸ������ĸ��̣�  
      if(i>k)//a���Ƚϴ�ȷ�е�˵�ǱȽϳ���  
      {//cout<<"I am 1"<<endl;  
          while(i>=0)  
          {  
               
             m=a[i]-'0';  
             sum[q++]=(temp+m)%10;  
             temp=(temp+m)/10;//�ӵ��Ŀӣ����������һ�Σ��ұ�����temp+m+n��Ȼ��֪Ϊ�δ��ˣ����Ѳ���ģ�  
  
             i--;  
          }  
      }  
      if(k>i)  
      {  
         // cout<<"I am 2"<<endl;  
        // cout<<"k="<<k<<" "<<"temp="<<temp<<endl;  
         while(k>=0)  
          {  
             m=b[k]-'0';//����Ҳ������һ�Σ��Ұ�bд����a��ȫ�Ǹ���ճ���ǵĻ�  
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
     //printf("%d",sum[--q]);//��һ���������ݳɹ���  
    // for(--q;q>=0;q--)  
    // {  
    //   printf("%04d",sum[q]);  
    // }  
     cout<<endl;  
     if(l<num-1) cout<<endl;  
  
    }//for  
return 0;
}  

