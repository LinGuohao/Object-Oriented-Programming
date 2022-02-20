#include<iostream>
using namespace std;
typedef struct{
	int a,b,c,d;
}wall;

int main()
{
	int n;
	cin >> n;
	wall mywall[n];
	wall space;
	cin >> space.a >> space.b >> space.c >> space.d;
	for(int i=0;i<n;i++)
	{
		cin>> mywall[i].a>> mywall[i].b >> mywall[i].c >> mywall[i].d;
	}
	//test
/*	cout << space.a << space.b << space.c <<space.d;
	for(int i=0;i<n;i++)
	{
		cout << mywall[i].a << mywall[i].b << mywall[i].c << mywall[i].d;
	}*/

// top
	int cntt,ctl;
	int tmpt[n];
	int tmpt2[n];
	cntt = 0;
	ctl = 0;
	for (int i=0;i<n;i++)
	{
		if(mywall[i].b == space.b)
		{
		tmpt[cntt] = mywall[i].a;
		tmpt2[cntt] = mywall[i].c;
		cntt++;
		ctl++;
	    }
	    
	}
	if(cntt == 0)
     cntt = 1;
	if (cntt>0 && ctl>0)
	{
		cntt = cntt+1;
		for (int i=0;i<ctl;i++)
		{
			if (tmpt[i] == space.a)
		   cntt = cntt-1;
          	if(tmpt2[i] == space.c)
			  cntt = cntt-1;
			if (tmpt2[i]+1== tmpt[i+1] )	
			cntt = cntt-1;
	   }
     }
     
//left
     int cntl,ctl1;
	int tmpl[n];
	int tmpl2[n];
	cntl = 0;
	ctl1 = 0;
	for (int i=0;i<n;i++)
	{
		if(mywall[i].a == space.a)
		{
		tmpl[cntl] = mywall[i].b;
		tmpl2[cntl] = mywall[i].d;
		cntl++;
		ctl1++;
	    }
	    
	}
	if (cntl == 0)
     cntl = 1;
	if (cntl>0 && ctl1>0)
	{
		cntl = cntl+1;
		for (int i=0;i<ctl1;i++)
		{
			if (tmpl[i] == space.b)
		   cntl = cntl-1;
          	if(tmpl2[i] == space.d)
			  cntl = cntl-1;
			if (tmpl2[i]+1== tmpl[i+1] )	
			cntl = cntl-1;
	   }
     }
     
   //right  
          int cntr,ctl2;
	int tmpr[n];
	int tmpr2[n];
	cntr = 0;
	ctl2 = 0;
	for (int i=0;i<n;i++)
	{
		if(mywall[i].c == space.c)
		{
		tmpr[cntr] = mywall[i].b;
		tmpr2[cntr] = mywall[i].d;
		cntr++;
		ctl2++;
	    }
	    
	}
	if(cntr == 0)
     cntr = 1;
	if (cntr>0 && ctl2>0)
	{
		cntr = cntr+1;
		for (int i=0;i<ctl2;i++)
		{
			if (tmpr[i] == space.b)
		   cntr = cntr-1;
          	if(tmpr2[i] == space.d)
			  cntr = cntr-1;
			if (tmpr2[i]+1== tmpr[i+1] )	
			cntr = cntr-1;
	   }
     }
     
    
//bottom 
int cntb,ctl3;
	int tmpb[n];
	int tmpb2[n];
	cntb = 0;
	ctl3 = 0;
	for (int i=0;i<n;i++)
	{
		if(mywall[i].d == space.d)
		{
		tmpb[cntb] = mywall[i].a;
		tmpb2[cntb] = mywall[i].c;
		cntb++;
		ctl3++;
	    }
	    
	}
	if (cntb == 0)
     cntb = 1;
	if (cntb>0 && ctl3>0)
	{
		cntb = cntb+1;
		for (int i=0;i<ctl3;i++)
		{
			if (tmpb[i] == space.a)
		   cntb = cntb-1;
          	if(tmpb2[i] == space.c)
			  cntb = cntb-1;
			if (tmpb2[i]+1== tmpb[i+1] )	
			cntb = cntb-1;
	   }
     }
     
     
  cout<< cntl <<" "<<cntb<<" "<<cntr<<" "<<cntt;






}
