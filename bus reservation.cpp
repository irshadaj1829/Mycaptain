#include<bits/stdc++.h>
 using namespace std;

int p=0;

class BUS

{

  char busno[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];

public:

  void newbus();

  void allotment();

  void empty();

  void show();

  void avail();

  void position(int i);

}

bus[10];

void vline(char ch)

{

  for (int i=100;i>0;i--)
       cout<<ch;
}

void BUS::newbus()

{

  cout<<"Enter bus no: ";

  cin>>bus[p].busno;

  cout<<"\nEnter Driver's name: ";

  cin>>bus[p].driver;

  cout<<"\nArrival time : ";

  cin>>bus[p].arrival;

  cout<<"\nDeparture: ";

  cin>>bus[p].depart;

  cout<<"\nFrom: \t";

  cin>>bus[p].from;

  cout<<"\nTo: \t";

  cin>>bus[p].to;

  bus[p].empty();

  p++;

}

void BUS::allotment()

{

  int seat;

  char number[5];

  top:

  cout<<"Bus no: ";

  cin>>number;

  int n;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].busno, number)==0)

    break;

  }

  while(n<=p)

  {

    cout<<"\nSeat Number: ";

    cin>>seat;

    if(seat>32)

    {

      cout<<"\nThere are only 32 seats available in this bus.";

    }

    else

    {

    if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)

      {

        cout<<"Enter passanger's name: ";

        cin>>bus[n].seat[seat/4][(seat%4)-1];

        break;

      }

    else

      cout<<"The seat number is already reserved.\n";

      }

      }

    if(n>p)

    {

      cout<<"Enter correct bus no.\n";
      goto top;

    }

  }


void BUS::empty()

{

  for(int i=0; i<8;i++)

  {

    for(int j=0;j<4;j++)

    {

      strcpy(bus[p].seat[i][j], "Empty");

    }

  }

}

void BUS::show()

{

  int n;

  char number[5];

  cout<<"Enter bus no: ";

  cin>>number;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].busno, number)==0)

    break;

  }

while(n<=p)

{

  vline('*');

  cout<<"Bus no: \t"<<bus[n].busno

  <<"\nDriver: \t"<<bus[n].driver<<"\t\tArrival time: \t"

  <<bus[n].arrival<<"\tDeparture time:"<<bus[n].depart

  <<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t"<<

  bus[n].to<<"\n";

  vline('*');
  cout<<'\n';
  bus[0].position(n);

  int a=1;

  for (int i=0; i<8; i++)

  {

    for(int j=0;j<4;j++)

    {

      a++;

      if(strcmp(bus[n].seat[i][j],"Empty")!=0)

      cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";

    }

  }

  break;

  }

  if(n>p)

    cout<<"Enter correct bus no: ";

}

void BUS::position(int l)

{

  int s=0;p=0;

  for (int i =0; i<8;i++)

  {

    cout<<"\n";

    for (int j = 0;j<4; j++)

    {

      s++;

      if(strcmp(bus[l].seat[i][j], "Empty")==0)

        {

          cout.width(5);

          cout.fill(' ');

          cout<<s<<".";

          cout.width(10);

          cout.fill(' ');

          cout<<bus[l].seat[i][j];

          p++;

        }

        else

        {

        cout.width(5);

        cout.fill(' ');

        cout<<s<<".";

        cout.width(10);

        cout.fill(' ');

        cout<<bus[l].seat[i][j];

        }

      }

    }

  cout<<"\n\nThere are "<<p<<" seats empty in Bus No: "<<bus[l].busno;

  }

void BUS::avail()

{


  for(int n=0;n<p;n++)

  {

    cout<<"Bus no: \t"<<bus[n].busno<<"\nDriver: \t"<<bus[n].driver

    <<"\t\tArrival time: \t"<<bus[n].arrival<<"\tDeparture Time: \t"

    <<bus[n].depart<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t\t"

    <<bus[n].to<<"\n";
                    if(n!=p-1)   
					vline('.');cout<<'\n';
  }

}

int main()

{


  int z;
   
  while(1)

 {
 

  cout<<"\n\n";

  cout<<"\t1.New Bus Details:\n\t"

  <<"2.Reservation of seats:\n\t"

  <<"3.Show the bus seats Available:\n\t"

  <<"4.Buses Available: \n\t"

  <<"5.Exit";

  cout<<"\n\t\tEnter your choice:- ";

  cin>>z;

  switch(z)

  {

    case 1: vline('*');
            cout<<'\n'; 
	        bus[p].newbus();
            vline('*');
      break;

    case 2: vline('*');
            cout<<'\n'; 
	        bus[p].allotment();
            vline('*');
      break;

    case 3: vline('*');
            cout<<'\n'; 
	        bus[0].show();
            vline('*');
      break;

    case 4: vline('*');
            cout<<'\n'; 
	        bus[0].avail();
            vline('*');
      break;

    case 5:  {
      cout<<"Successfully Logout from Application"<<endl<<"***Thanks You***";
      exit(0);
    };
   
   
  }

 }

 return 0;

}
