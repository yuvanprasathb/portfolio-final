#include<iostream.h>
#include<conio.h>
#include<stdio.h>

//****************************************************************************
//**********************************Account***********************************
//****************************************************************************

class account
{
private:

char name[50];
int ano;
char atype[50];

public :

void getacdet()
{
cout<<"Enter customer name : ";
gets(name);
cout<<"Enter A/c Number : ";
cin>>ano;
cout<<"Enter A/c Type : ";
gets(atype);
}

void displaydet()
{
cout<<"Customer name : "<<name<<endl;
cout<<"A/c Number : "<<ano<<endl;
cout<<"A/c Type : "<<atype<<endl;
}
};
//***************************************************************************
//*****************************Current Account*******************************
//***************************************************************************
class currentaccount:public account
{
public :

float balance;

public :

void c_display()
{
cout<<"Balance : "<<balance<<endl;
}

void c_deposit()
{
float deposit;
cout<<"Enter amount of Deposit : "<<endl;
cin>>deposit;
balance=balance+deposit;
cout<<"Balance after Deposit : "<<balance;
}


void c_withdraw()
{
float withdraw;
cout<<"Balance : "<<balance<<endl;
cout<<"Enter amount to withdraw : ";
cin>>withdraw;
if(balance>1000)
{
if(withdraw>balance)
{
cout<<"Insufficient Balance"<<endl;
}
else{
balance=balance-withdraw;
cout<<"Balance amount after withdraw : "<<balance;
}
}
else
{
cout<<"Insufficient Balance"<<endl;
}
}
};

//****************************************************************************
//******************************Saving Account********************************
//****************************************************************************
class savingaccount:public account
{
public:

float sav_balance;

public:

void s_display()
{
cout<<"Balance : "<<sav_balance<<endl;
}

void s_deposit()
{
float deposit,interest;
cout<<"Enter amount to deposit : ";
cin>>deposit;
sav_balance=sav_balance+deposit;
interest=(sav_balance*2)/100;
sav_balance=sav_balance+interest;
cout<<"Balance amount after deposit  with interest : "<<sav_balance<<endl;
}

void s_withdraw()
{
float withdraw;
cout<<"Balance : "<<sav_balance<<endl;
cout<<"Enter amount to withdraw : ";
cin>>withdraw;
if(sav_balance>500)
{
if(withdraw>sav_balance)
{
cout<<"Insufficent Balance"<<endl;
}
else
{
sav_balance=sav_balance-withdraw;
cout<<"Balance after withdraw : "<<sav_balance<<endl;
}
}
else{
cout<<"Insufficient balance "<<endl;
}
}
};

//**************************************************************************
//*****************************Fixed Deposit**********************************
//**************************************************************************

class fixeddeposit:public account
{
public:
float fd_amount,time,fd_tot;

void fd_input()
{
cout<<"Enter Fixed Deposit Amount : ";
cin>>fd_amount;
cout<<"Enter Time Period of Fixed Deposit (in months): ";
cin>>time;
}
void fd_calc()
{
if(fd_amount>10000&&time>24)
{
fd_tot=((fd_amount*time)*0.05);
fd_tot+=fd_amount*time;
cout<<"\nAmount in Fixed Deposit After Time Period : "<<fd_tot<<endl;
}
else
{
cout<<"There is no Minimum Amount or Time Period for Fixed Deposit "<<endl;
}
}

void fd_display()
{
cout<<"Amount Paid per month in Fixed Deposit :"<<fd_amount<<endl;
cout<<"Time Period in Fixed Deposit (in months) : "<<time<<endl;
cout<<"Total Amount in Fixed Deposit for 5% Interest Rate : "<<fd_tot<<endl;
}
};

//****************************************************************************
//*****************************Main function**********************************
//****************************************************************************
int main()
{
char type;
int choice;
clrscr();
currentaccount c1;
fixeddeposit f1;
savingaccount s1;
c1.balance=0;
s1.sav_balance=0;
cout<<"Enter\n'S' for Saving account\n\t(or)\n'C' for Current account\n\t(or)\n'F' for Fixed Deposit :";
cin>>type;
cout<<endl;
if(type=='S'||type=='s')
{
s1.getacdet();
while(1)
{
cout<<"\n Choose your choice:"<<endl;
cout<<"1)Deposit "<<endl;
cout<<"2)withdraw "<<endl;
cout<<"3)Display Balance "<<endl;
cout<<"4)Display with Full details "<<endl;
cout<<"5)Exit\n"<<endl;
cin>>choice;
switch(choice)
{
case 1:
s1.s_deposit();
break;
case 2:
s1.s_withdraw();
break;
case 3:
cout<<"_________________________________________________________________________"<<endl;
s1.s_display();
cout<<"_________________________________________________________________________"<<endl;
break;
case 4:
cout<<"_________________________________________________________________________"<<endl;
s1.displaydet();
s1.s_display();
cout<<"_________________________________________________________________________"<<endl;
break;
case 5:
goto end;
default:
cout<<"\nEntered choice is Invalid Please try again";
}
}
}

else if(type=='C'||type=='c')
{

c1.getacdet();
while(1)
{
cout<<"\n Choose your choice : "<<endl;
cout<<"1)Deposit "<<endl;
cout<<"2)Withdraw "<<endl;
cout<<"3)display balance"<<endl;
cout<<"4)display with full details"<<endl;
cout<<"5)exit\n"<<endl;
cin>>choice;
cout<<endl;
switch (choice)
{
case 1:
c1.c_deposit();
break;
case 2:
c1.c_withdraw();
break;
case 3:
cout<<"__________________________________________________________________________"<<endl;
c1.c_display();
cout<<"__________________________________________________________________________"<<endl;
break;
case 4:
cout<<"__________________________________________________________________________"<<endl;
c1.displaydet();
c1.c_display();
cout<<"__________________________________________________________________________"<<endl;
break;
case 5:
goto end;
default:
cout<<"\nEntered choice is Invalid or try again ";
}
}
}
else if(type=='F'||type=='f')
{
f1.getacdet();
while(1){
cout<<"\n Choose your choice : "<<endl;
cout<<"1)Fixed Deposit Creation : "<<endl;
cout<<"2)Fixed Deposit amount : "<<endl;
cout<<"3)Fixed Deposit Details : "<<endl;
cout<<"4)Exit : \n"<<endl;
cin>>choice;
cout<<endl;
switch(choice)
{
case 1:
f1.fd_input();
break;
case 2:
cout<<"________________________________________________________________________"<<endl;
f1.fd_calc();
cout<<"________________________________________________________________________"<<endl;
break;
case 3:
cout<<"_________________________________________________________________________"<<endl;
f1.displaydet();
f1.fd_display();
cout<<"_________________________________________________________________________"<<endl;
break;
case 4:
goto end;
default:
cout<<"Invalid Input "<<endl;
}
}
    }
else
{
cout<<"Invalid A/c Selection"<<endl<<endl;
}
end:
cout<<"********************************************************************************"<<endl;
cout<<"\t\t\tThank you for banking with us!!!"<<endl;
cout<<"********************************************************************************"<<endl;
getch();

return 0;
}





