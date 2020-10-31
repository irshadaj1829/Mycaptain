#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<iomanip>
#include<cstring>
#include<conio.h>
using namespace std;

int main()
{
	FILE *fp,*ft;
	char choice,another;

	struct student
	{
		char fname[10];
		char lname[10];
		char course[50];
		int section;
	};

	struct student s1;
	char xfname[10],xlname[10];
	long int recsize;

	fp=fopen("users.txt","rb+");
	if(fp==NULL)
	{
		fp=fopen("users.txt","wb+");

		if(fp==NULL)
		{
			puts("Cannot open this file ");
			return 0;
		}
	}

	recsize = sizeof(s1);

	while(1)
	{
		system("cls");

		cout<<"\t\t+++++++ STUDENT'S DATABASE MANAGEMENT SYSTEM (DBMS)++++++++";
		cout<<"\n\n";

		cout<<"\n\t\t\t 1.Add Records";
		cout<<"\n\t\t\t 2.List Records";
		cout<<"\n\t\t\t 3.Modify Records";
		cout<<"\n\t\t\t 4.Delete Records";
		cout<<"\n\t\t\t 5.Exit Program";
		cout<<"\n\n";
		cout<<"\t\t\t Select your choice :=> ";

		fflush(stdin);
		choice=getchar();

		switch(choice)
		{
			case '1':
			fseek(fp,0,SEEK_END);
			another='Y';

			while(another=='Y'|| another=='y')
			{
				system("cls");
				cout<<"\nEnter your first name :";
				cin>>s1.fname;

				cout<<"\nEnter your last name :";
				cin>>s1.lname;

				cout<<"\nEnter the course   : ";
				cin>>s1.course;

				cout<<"\nEnter the section  : ";
				cin>>s1.section;

				fwrite(&s1,recsize,1,fp);
				cout<<"\n Add Another Record (Y/N) ";
				fflush(stdin);
				another=getchar();
				}
			break;

            case '2':
                system("cls");
				rewind(fp);

				cout<<"\n======VIEW THE RECORDS IN THE DATABASE=======";
				cout<<endl;
				while(fread(&s1,recsize,1,fp)==1)
				{
					cout<<"\n"<<s1.fname<<setw(10)<<s1.lname;
					cout<<"\n";
					cout<<"\n"<<s1.course<<setw(8)<<s1.section;
				}
				cout<<"\n\n";
				system("pause");
				break;

			case '3':
				system("cls");
				another='Y';
				while(another=='Y'|| another=='y')
				{
					cout<<"\n Enter the last name of the student :";
					cin>>s1.lname;

					rewind(fp);
					while(fread(&s1,recsize,1,fp)==1)
					{
						if(strcmp(s1.lname,xlname)==0)
						{
							cout<<"\nEnter new First name :";
							cin>>s1.fname;

							cout<<"\nEnter new Last name :";
							cin>>s1.lname;

							cout<<"\nEnter the new Course  :";
							cin>>s1.course;

							cout<<"\nEnter the new section  :";
							cin>>s1.section;

							fseek(fp,recsize,SEEK_CUR);
							fwrite(&s1,recsize,1,fp);
							break;
						}
						else
						cout<<"Record Not Found";
					}
					cout<<"\n Modify Another Record (Y/N)";
					fflush(stdin);
					another=getchar();
				}
				break;

				case '4':
					system("cls");
					another = 'Y';
					while(another =='Y'|| another =='y')
					{
						cout<<"\n Enter the Last name of the student to delete :";
						cin>>s1.lname;

						ft=fopen("temp.dat","wb");
						rewind(fp);

						while(fread(&s1,recsize,1,fp)==1)
						{
							if(strcmp(s1.lname,xlname)!=0)
							{
								fwrite(&s1,recsize,1,fp);
							}
						fclose(fp);
						fclose(ft);
						remove("users.txt");
						rename("temp.dat","users.txt");

						fp=fopen("users.txt","rb+");

						cout<<"\n Delete Another Record (Y/N) ";
						fflush(stdin);
						another=getchar();

						}
					}
					break;

					case '5':
						fclose(fp);
						cout<<"\n\n";
						cout<<"\t\t *******THANK YOU ******* ";
						cout<<"\n\n";
						exit(0);
				}
}

system("pause");
return 0;
}
