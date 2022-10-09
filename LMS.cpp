#include<fstream>
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<iomanip>
using namespace std;


class student_profile
{
	char name[30];
	int reg_year;
	protected:
	long int prn_no;
    public:
    void getdata()
    {
    	cout<<"\nEnter your Name:";
        getchar();
        gets(name);
        cout<<"\nEnter your registration year:";
        cin>>reg_year;
        cout<<"\nEnter your prn number:";
        cin>>prn_no;
    }
    void display()
    {
        cout<<"\nPRN number:"<<prn_no<<endl;
        cout<<"Student Name:"<<name<<endl;
        cout<<"Registration year:"<<reg_year<<endl;

    }
    void print1()
    {
        cout<<setw(30)<<prn_no<<setw(30)<<name<<setw(30)<<reg_year<<endl;
    }
    int return_prn()
    {
    	return prn_no;
    }
}student;

class stud:public student_profile
{
	char notebooks[30];
    char issue_date[20];
    char status[20];
    public:
    char* return_nb()
    {
        return notebooks;
    }
    void borrow(char n[])
    {

        cout<<"\nPlease re-enter the prn no to confirm:";
        cin>>prn_no;
        getchar();
        cout<<"Enter the issue date of book:";
    	gets(issue_date);
    	strcpy(notebooks,n);
    	strcpy(status,"Borrowed");

    }
    void display1()
    {
    	cout<<setw(35)<<"Books"<<setw(35)<<"Issue date"<<setw(35)<<"Status"<<endl;
    }
    void display2()
    {
        	cout<<setw(35)<<notebooks<<setw(35)<<issue_date<<setw(35)<<status<<endl;
    }
}st;

class books
{
	int id;
	char genre[30];
	char b_name[60];
	char author_name[40];
	int price;
	int quantity;
    public:
	void getdata()
	{
	    cout<<"Enter ID: ";
	    cin>>id;
	    cout<<"\nEnter Genre: ";
	    getchar();
	    gets(genre);
	    getchar();
	    cout<<"Enter Name: ";
	    gets(b_name);
	    getchar();
	    cout<<"Enter Author Name: ";
	    gets(author_name);
	    cout<<"\nEnter price: ";
	    cin>>price;
	    cout<<"\nEnter Quantity: ";
	    cin>>quantity;
	}
	void display()
	{
		cout<<"\nID: "<<id<<endl;
		cout<<"Genre: "<<genre<<endl;
		cout<<"Book name: "<<b_name<<endl;
		cout<<"Author name: "<<author_name<<endl;
		cout<<"Price: "<<price<<endl;
		cout<<"Quantity: "<<quantity<<endl;

	}
	void print()
	{
	    cout<<setw(15)<<id<<setw(20)<<genre<<setw(45)<<b_name<<setw(30)<<author_name<<setw(20)<<price<<setw(15)<<quantity<<endl;
	}

	int getid()
	{
		return id;
	}
	int return_quantity()
	{
		return quantity;
	}
	char* getgenre()
	{
		return genre;
	}
	char* getbname()
	{
		return b_name;
	}
	char* getauth()
	{
		return author_name;
	}
	void update_q(int n)
	{
		quantity=n;
	}
}b;
void info(int i)
{
ifstream fout("Student.dat",ios::binary|ios::in);
while(fout.read((char*)&student,sizeof(student)))
    {
        if(student.return_prn()==i)
        {
            student.display();
            break;
        }
        if(fout.eof())
        break;
    }
fout.close();
}

void borrow_up(char ch[])
{
    char i[20];
    int flag=0,temp=0;
    int qu;
    std::strcpy(i,ch);
    fstream fin;
    fin.open("books.dat",ios::binary|ios::in|ios::out);
    while(fin.read((char*)&b,sizeof(b)))
    {
        if(strcmpi(b.getbname(),i)==0)
        {
            flag=1;
            qu=b.return_quantity();
            break;
        }
        else
        temp++;
     }
     if(flag==1)
     {
         getchar();
         qu=qu-1;
         long int pos=(temp)*sizeof(b);
         fin.seekp(pos);
         b.update_q(qu);
         fin.write((char*)&b,sizeof(b));
      }
      fin.close();
}

void return_up(char ch[])
{
    char i[20];
    int flag=0,temp=0;
    int qu;
    std::strcpy(i,ch);
    fstream fin;
    fin.open("books.dat",ios::binary|ios::in|ios::out);
    while(fin.read((char*)&b,sizeof(b)))
    {
        if(strcmpi(b.getbname(),i)==0)
        {
            flag=1;
            qu=b.return_quantity();
            break;
        }
        else
        temp++;
     }
     if(flag==1)
     {
         getchar();
         qu=qu+1;
         long int pos=(temp)*sizeof(b);
         fin.seekp(pos);
         b.update_q(qu);
         fin.write((char*)&b,sizeof(b));
      }
      fin.close();
}

void admin_1()
{
    	try
    	{
    	int pass;
    	cout<<"Enter the password:";
    	cin>>pass;
    	if(pass==1234)
        {
            int choice;
            do
            {
            	cout<<"\nENTER WHAT MODULE YOU WANT TO OPEN"<<endl;
                cout<<"1.REPORT MODULE\n2.BOOK MANAGEMENT MODULE\n3.STUDENT MODULE\n4.EXIT FROM THE WHOLE PROGRAM\nPRESS ANY OTHER NUMBER TO EXIT FROM CURRENT BLOCK"<<endl;
                cin>>choice;
                switch(choice)
                {
                	case 1:
                	       int r;
                	       do
                           {
                           	cout<<"\nWHAT YOU WANT TO DO IN REPORT MODULE"<<endl;
                            cout<<"1.RENTAL REPORT\n2.BOOK REPORT\n3.STUDENT PROFILE REPORT\n4.EXIT FROM THE WHOLE PROGRAM\nPRESS ANY OTHER NUMBER TO EXIT FROM CURRENT BLOCK"<<endl;
                            cin>>r;
                            switch(r)
                            {
                            	case 1:{
                            	       ifstream obj("Student_books.dat",ios::binary|ios::in);
	                                   while(obj.read((char*)&st,sizeof(st)))
	                                   {
                                        int z=st.return_prn();
                                        info(z);
	                                    st.display1();
	                                    st.display2();
	                                    cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
	                                    if(obj.eof())
                                        break;
	                                   }
	                                    obj.close();
	                                   break;}

                                case 2:{ifstream fout("books.dat",ios::binary|ios::in);
                                       cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
                                       cout<<setw(15)<<"ID"<<setw(20)<<"Book Genre"<<setw(45)<<"Book Name"<<setw(30)<<"Book Author"<<setw(20)<<"Book Price"<<setw(15)<<"Quantity\n"<<endl;
	                                   while(fout.read((char*)&b,sizeof(b)))
                                       {
                                       	b.print();
                                       	if(fout.eof())
                                       	break;
                                       }
                                       cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
                                       fout.close();
                                       break;}
                                case 3:{ifstream fout("Student.dat",ios::binary|ios::in);
                                       cout<<"-------------------------------------------------------------------------------------------------------"<<endl;
                                       cout<<setw(30)<<"Student Prn No"<<setw(30)<<"Student Name"<<setw(30)<<"Student Registration year"<<endl<<endl;
	                                   while(fout.read((char*)&student,sizeof(student)))
	                                   {
	                                   	student.print1();
	                                    if(fout.eof())
	                                    break;
	                                   }
	                                   cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
	                                    fout.close();

	                                   break;}
                                case 4:exit(0);
                            }
                           }while(r<5);
                           break;
                    case 2:{int r;
                           do
                           {
                           	cout<<"\nWHAT YOU WANT TO DO IN BOOK MANAGEMENT MODULE"<<endl;
                            cout<<"1.SEARCH A BOOK BY BOOK NAME\n2.REGISTER A NEW BOOK(Id of the book should be unique)\n3.EDIT A BOOK INFORMATION\n4.DELETE A BOOK INFORMATION\n5.EXIT FROM THE WHOLE PROGRAM\nPRESS ANY OTHER NUMBER TO EXIT FROM CURRENT BLOCK"<<endl;
                            cin>>r;
                            switch(r)
                            {
                            	case 1: {char name2[40];
                            	         int flag=0;
	                                    cout<<"\nEnter the name of book you want to search:";
	                                    getchar();
	                                    gets(name2);
	                                    ifstream obj("books.dat",ios::binary|ios::in);
	                                	while(obj.read((char*)&b,sizeof(b)))
	                                	{
	                                		if(strcmpi(b.getbname(),name2)==0)
	                                		{
	                                		    cout<<"Book Found!!!!!!"<<endl;
	                                			b.display();
	                                			flag++;
	                                		}
	                                		if(obj.eof())
	                                		break;
	                                	}
	                                	if(flag==0)
                                            cout<<"No book with such name in the library"<<endl;
	                                	obj.close();
	                                	break;}
	                            case 2:{
	                                    ofstream obj("books.dat",ios::binary|ios::app);
                                        b.getdata();
                                        obj.write((char*)&b,sizeof(b));
                                        obj.close();
	                                    break;}
	                            case 3:{int k;
	                                   do
	                                   {
	                                   cout<<"\nEnter what you want to edit"<<endl;
	                                   cout<<"1.Book name\n2.Author Name\n3.Quantity\n4.Exit from the whole program\nPress any other number to exit from current block"<<endl;
	                                   cin>>k;

	                                   switch(k)
	                                   {
	                                   	case 1:{char i[20];
	                               	           char new_name[20];
	                               	           int flag=0,temp=0;
	                               	           getchar();
	                               	           cout<<"\nEnter the book name you want to edit:";
	                               	           gets(i);
	                               	           fstream fin;
	                               	           fin.open("books.dat",ios::binary|ios::in|ios::out);
	                               	           while(fin.read((char*)&b,sizeof(b)))
	                               	           {

	                               	               if(strcmp(b.getbname(),i)==0)
	                               	         	   {
	                               	           	    flag=1;
	                               	           	    break;
                                                   }
	                               	           	   else
	                               	           	       temp++;
	                               	            }
	                               	         	if(flag==1)
	                               	            {
	                               	                getchar();
	                               	       	        cout<<"Enter new book name:";
	                               	       		    gets(new_name);
	                               	       		    long int pos=(temp)*sizeof(b);
	                               	       		    fin.seekp(pos);
	                               	       		    strcpy(b.getbname(),new_name);
	                               	       		    fin.write((char*)&b,sizeof(b));
	                               	       		    cout<<"Record modified successfully!!!"<<endl;
	                               	       	    }
	                               	       	    else
	                               	       	    {
	                               	       		    cout<<"Record not found"<<endl;
	                               	       	    }
	                               	            fin.close();

	                               	            break;}

	                                 	case 2:{char i[20];
	                               	           char new_name[20];
	                               	           int flag=0,temp=0;
	                               	           getchar();
	                               	           cout<<"\nEnter the author name you want to edit:";
	                               	           gets(i);
	                               	           fstream fin("books.dat",ios::binary|ios::in|ios::out);

	                               	           while(fin.read((char*)&b,sizeof(b)))
	                               	           {
	                               	           	if(strcmpi(b.getauth(),i)==0)
	                               	         	{
	                               	           	    flag=1;
	                               	           	    break;
	                               	            }
	                               	           	else
	                               	           	    temp++;
	                               	            }
	                               	         	if(flag==1)
	                               	            {
	                               	                getchar();
	                               	       	        cout<<"Enter new author name:";
	                               	       		    gets(new_name);
	                               	       		    long int pos=(temp)*sizeof(b);
	                               	       		    fin.seekp(pos);
	                               	       		    strcpy(b.getauth(),new_name);
	                               	       		    fin.write((char*)&b,sizeof(b));
	                               	       		    cout<<"Record modified successfully!!!!"<<endl;
	                               	       	    }
	                               	       	    else
	                               	       	    {
	                               	       		    cout<<"Record not found"<<endl;
	                               	       	    }
	                               	            fin.close();

	                               	            break;}
	                               	    case 3:{int in;
	                               	           int qu;
	                               	           int flag=0,temp=0;
	                               	           cout<<"\nEnter the id of the book whose quantity you want to edit:";
	                               	           cin>>in;
	                               	           fstream fin("books.dat",ios::binary|ios::in|ios::out);

	                               	           while(fin.read((char*)&b,sizeof(b)))
	                               	           {
	                               	       	    if(b.getid()==in)
	                               	       	    {
	                               	           	    flag=1;
	                               	           	    break;
	                               	            }
	                               	           	else
	                               	           	    temp++;
	                               	           }
	                               	         	if(flag==1)
	                               	            {

	                               	       	        cout<<"Enter new quantity:";
	                               	       	    	cin>>qu;
	                               	       		    long int pos=(temp)*sizeof(b);
	                               	       		    fin.seekp(pos);
	                               	       		    b.update_q(qu);
	                               	       		    fin.write((char*)&b,sizeof(b));
	                               	       		    cout<<"Record modified successfully!!!"<<endl;
	                               	       	    }
	                               	       	    else
	                               	       	    {
	                               	       		    cout<<"Record not found"<<endl;
	                               	       	    }
	                               	           fin.close();

                                               break;}
                                         case 4:exit(0);
	                                    }
	                                   }while(k<5);
	                                   break;}
	                            case 4:{int x=0;
	                                   int ino;
	                                   cout<<"\nEnter the id number of the book you want to delete:";
	                                   cin>>ino;
	                                   ifstream obj("books.dat",ios::binary|ios::in);
	                                   ofstream fout("temp.dat",ios::binary|ios::out);
	                                   while(obj.read((char*)&b,sizeof(b)))
	                                   {
	                                   	if(b.getid()!=ino)
	                                    {
	                                    	fout.write((char*)&b,sizeof(b));
	                                    }
	                                    else
	                                    {
	                                    	x++;
	                                    }
	                                    if(obj.eof())
	                                    break;
	                                   }
	                                   if(x!=0)
	                                   {
	                                   obj.close();
	                                   fout.close();
	                                   remove("books.dat");
	                                   rename("temp.dat","books.dat");
	                                   cout<<"Record deleted Successfully!!!"<<endl;
	                                   }
	                                   else
                                        cout<<"No such record found."<<endl;
	                                   break;}
                                case 5:exit(0);
                            }
                           }while(r<6);
                           break;}
                    case 3:int sk;
                           do
                           {
                           	cout<<"\nWHAT YOU WANT TO DO IN STUDENT MANAGEMENT MODULE"<<endl;
                            cout<<"1.SEARCH A STUDENT INFORMATION\n2.DELETE A STUDENT\n3.EXIT FROM THE WHOLE PROGRAM\nPRESS ANY OTHER NUMBER TO EXIT FROM THE CURRENT BLOCK"<<endl;
                            cin>>sk;
                            switch(sk)
                            {
                            	case 1:{int flag=0;
                            	       ifstream obj("Student.dat",ios::binary|ios::in);
	                                   int x;
	                                   cout<<"\nEnter the prn number of the student you want to search:";
	                                   cin>>x;
	                                   while(obj.read((char*)&student,sizeof(student)))
	                                   {
	                                   	if(student.return_prn()==x)
	                                    {
	                                    	cout<<"\n----------The student details are:-----------"<<endl;
	                                        student.display();
	                                        flag++;
	                                        break;
	                                    }
                                        if(obj.eof())
                                        break;
	                                   }
	                                   if(flag==0)
                                        cout<<"No such record"<<endl;
	                                   obj.close();
	                                   break;
	                                   }
                                case 2:{
                                       int x=0;
	                                   int ino;
	                                   cout<<"\nYou can only delete one student record if he has returned all the books"<<endl;
	                                   cout<<"\nEnter the prn number of the student you want to delete:";
	                                   cin>>ino;
	                                   ifstream obj("Student.dat",ios::binary|ios::in);
	                                   ofstream fout("temp.dat",ios::binary|ios::out);
	                                   while(obj.read((char*)&student,sizeof(student)))
	                                   {
	                                   	if(student.return_prn()!=ino)
	                                    {
	                                    	fout.write((char*)&student,sizeof(student));
	                                    }
	                                    else
	                                    {
	                                    	x++;
	                                    }
	                                    if(obj.eof())
	                                    break;
	                                   }
	                                   if(x!=0)
	                                   {
	                                   obj.close();
	                                   fout.close();
	                                   remove("Student.dat");
	                                   rename("temp.dat","Student.dat");
	                                   cout<<"Record deleted successfully!!!!"<<endl;
	                                   }
	                                   else
                                        cout<<"No record found"<<endl;
	                                   break;
	                                   }
                                case 3:exit(0);
                             }
                            }while(sk<4);
                            break;
                   case 4:exit(0);
                 }
            }while(choice<5);
        }
        else
        {
        	throw(pass);
        }
        }
        catch(int th)
        {
        	cout<<"Exception caught"<<endl;
        	cout<<"Your password is incorrect"<<endl;
        	cout<<"You can't enter as an admin"<<endl;
        	exit(0);
        }
}


void student_1()
{
    int x;
    do
    {
    cout<<"\n1.NEW REGISTRATION\n2.ALREADY A MEMBER\n3.EXIT FROM THE WHOLE PROGRAM\nEXIT FROM THE CURRENT BLOCK"<<endl;
    cin>>x;
    switch(x)
    {
        case 1:{ofstream obj("Student.dat",ios::binary|ios::app);
               student.getdata();
               obj.write((char*)&student,sizeof(student));
               obj.close();
               cout<<"Registered Successfully!!!!!\n";
               break;}
        case 2:{
               int correct;
               cout<<"Enter your prn no: ";
               cin>>correct;
               int flag=0;
               ifstream obj("Student.dat",ios::binary|ios::in);
               while(obj.read((char*)&student,sizeof(student)))
               {
                int l=student.return_prn();
                if(correct==l)
                {
                 flag=1;
                 break;
                }
                else
                {
                  continue;
                }
               }
               obj.close();
               if(flag==1)
               {
                   cout<<"You are a member"<<endl;
                   cout<<"Use the same prn no when you are borrowing or returning a book."<<endl;
                    cout<<"--------You can choose a Module---------"<<endl;

               }
               else
               {
                   cout<<"You are not a member"<<endl;
                  cout<<"Please re-run the program";
                  exit(0);

               }
                    int choice;
    	            do
    	            {

                     cout<<"\nENTER WHAT MODULE YOU WANT TO OPEN"<<endl;
                     cout<<"1.SERCH AN ITEM\n2.DISPLAY ALL BOOKS ID,GENRE,NAME AND AUTHOR\n3.BORROW AN ITEM \n4.RETURN AN ITEM\n5.EDIT YOUR INFORMATION \n6.EXIT FROM THE WHOLE PROGRAM\nPRESS ANY OTHER NUMBER TO EXIT FROM THE CURRENT BLOCK"<<endl;
                     cin>>choice;
                     switch(choice)
                     {
        	           case 1:{int sear;
        	                   do
        	                   {
        	       	             cout<<"\nENTER THE WAY HOW YOU WANT TO SEARCH AN ITEM:"<<endl;
        	       	             cout<<"1.BY BOOK NAME\n2.BY GENRE\n3.BY AUTHOR\n4.EXIT THE WHOLE PROGRAM\nPRESS ANY OTHER NUMBER TO EXIT THE CURRENT BLOCK"<<endl;
        	       	             cin>>sear;
        	       	             switch(sear)
        	                   	 {
        	       		           case 1:{
        	       		                   char name[30];
        	       		                   int flag=0;
        	       		                   cout<<"\nEnter the name of the book you want to search:";
                                           getchar();
        	       		                   gets(name);
        	       		                   ifstream obj("books.dat",ios::binary|ios::in);
	                                       while(obj.read((char*)&b,sizeof(b)))
	                                       {
	                                         if(strcmpi(b.getbname(),name)==0)
	                                         {
	                                             cout<<"The Searched book details are:"<<endl;
	                                             b.display();
	                                             flag++;
	                                          }
	                                          if(obj.eof())
	                                          break;
	                                       }
                                            if(flag==0)
                                            {
                                                  cout<<"No such book there in the library."<<endl;
                                            }
	                                        obj.close();
	                                        break;
	                                        }
	                                case 2:{
	                                        char gen[20];
	                                        cout<<"\nWhat genre you want to search"<<endl;
	                                        cout<<"1.Fiction\n2.Non Fiction\n3.Magazine\n4.Nature"<<endl;
	                                        cout<<"\nEnter the name of the genre:";
	                                        getchar();
	                                        gets(gen);
	                                        if(strcmpi(gen,"Fiction")==0||strcmpi(gen,"Non Fiction")==0||strcmpi(gen,"Magazine")==0 ||strcmpi(gen,"Nature")==0)
                                            {
	                                        cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	                                        cout<<setw(15)<<"ID"<<setw(20)<<"Book Genre"<<setw(45)<<"Book Name"<<setw(30)<<"Book Author"<<setw(20)<<"Book Price"<<setw(15)<<"Quantity\n"<<endl;
	                                        ifstream obj("books.dat",ios::binary|ios::in);
	                                        while(obj.read((char*)&b,sizeof(b)))
	                                        {
	                                            if(strcmpi(b.getgenre(),gen)==0)
	                                            {
	                                                b.print();
	                                             }
	                                             if(obj.eof())
	                                             break;

	                                         }
	                                         cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
                                            }
	                                         else
                                                cout<<"No book with such genre in library"<<endl;
	                                         obj.close();
	                                         break;
	                                        }
                                    case 3:{int flag=0;
                                            char auth[30];
                                            cout<<"\nEnter the name of the author whose book you want to search:";
                                            getchar();
                                            gets(auth);
                                            ifstream obj("books.dat",ios::binary|ios::in);
	                                        while(obj.read((char*)&b,sizeof(b)))
	                                        {
	                                           if(strcmpi(b.getauth(),auth)==0)
	                                           {
	                                                cout<<"The searched author books are:"<<endl;
	                                                b.display();
	                                                flag++;
	                                           }
	                                        if(obj.eof())
	                                        break;
	                                        }
	                                        if(flag==0)
                                                cout<<"No book with such author name in the library"<<endl;
	                                        obj.close();
	                                        break;
	                                        }
                                     case 4:exit(0);
	                             }
	                            }while(sear<5);
	                            break;}
                       case 2:{ifstream fout("books.dat",ios::binary|ios::in);
                               cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
                               cout<<setw(15)<<"ID"<<setw(20)<<"Book Genre"<<setw(45)<<"Book Name"<<setw(30)<<"Book Author"<<setw(20)<<"Book Price"<<setw(15)<<"Quantity\n"<<endl;
                               while(fout.read((char*)&b,sizeof(b)))
                               {
                                 b.print();
                                 if(fout.eof())
                                 break;
                               }
                               cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
                                fout.close();
                                break;}

                       case 3:{
                               try
                               {
                                   int c;
                                   cout<<"Have you returned the previous borrowed book?"<<endl;
                                   cout<<"If you have returned or if you are borrowing the book for the first time press 1\nIf you have not then press 2"<<endl;
                                   cin>>c;
                                   if(c==1)
                                   {
                                       char name[30];
	                                   int z;
	                                   int flag=0;
	                                   ifstream obj("books.dat",ios::binary|ios::in);
                                       ofstream fout("Student_books.dat",ios::binary|ios::app);
	                                   cout<<"\nPlease enter your prn no:";
	                                   cin>>z;
	                                   cout<<"Enter the name of the book you want to borrow:";
                                       getchar();
	                                   gets(name);
	                                   while(obj.read((char*)&b,sizeof(b)))
	                                   {
	                                       if(strcmpi(b.getbname(),name)==0 && b.return_quantity()>0)
	                                       {
	                                           strcpy(name,b.getbname());
                                               borrow_up(b.getbname());
	                                           flag=1;
                                               break;
	                                       }
                                       }
	                                   obj.close();
	                                   if(flag==1)
                                       {
                                          st.borrow(name);
                                          fout.write((char*)&st,sizeof(st));
                                          fout.close();
                                          cout<<"!!!!Successfully Borrowed!!!!!"<<endl;
                                          cout<<"\n****Please return the book within 15 days else a fine of Rs.20 will be charged everyday after that.****"<<endl;
                                          cout<<"Also you can borrow a new book only if you return the previous one."<<endl;
                                       }
                                       else
                                       {
                                           cout<<"No such book there in library"<<endl;
                                       }
                                      }
                                      else
                                        throw(c);
                                }catch(int x)
                                {
                                    cout<<"Exception caught"<<endl;
                                    cout<<"You have not returned the previous book you can't borrow"<<endl;
                                    cout<<"Please return that first"<<endl;
                                    continue;
                                }
                               break;
	                           }
	                   case 4:{
	        	               char name3[30];
	                           int z,x=0;
	                           int choice;
	                           int da,fine=0;
	                           cout<<"\nEnter your prn no:";
	                           cin>>z;
	                           cout<<"\n******You can only return the book if you have paid the fine******"<<endl;
	                           cout<<"Enter after how many days are you returning the book:";
	                           cin>>da;
	                           if(da<15)
                               {
                                   fine=0;
                                   cout<<"You don't have to pay any fine\nPlease enter yes for the next statement."<<endl;
                               }
                               else
                               {
                                   fine=(da-15)*20;
                                   cout<<"\nYour fine is:"<<fine<<endl;
                                   cout<<"Please pay it."<<endl;
                               }
                               cout<<"\nHave you paid the fine:\n1.Yes\n2.No"<<endl;
                               cin>>choice;
                               if(choice==1)
                               {
                               cout<<"Enter the name of book you want to return:";
	                           getchar();
	                           gets(name3);
	                           ifstream obj("Student_books.dat",ios::binary|ios::in);
                               ofstream fout("temp.dat",ios::binary|ios::out);
	                           while(obj.read((char*)&st,sizeof(st)))
	                           {
	               	              if(st.return_prn()==z && strcmpi(st.return_nb(),name3)==0)
	               	              {

	               	                  x++;
                                  }
                                  else
                                  {
                                      fout.write((char*)&st,sizeof(st));

                                  }
                                  if(obj.eof())
                                  break;
                                }
                                if(x!=0)
                                {
                                obj.close();
                                fout.close();
                                remove("Student_books.dat");
                                rename("temp.dat","Student_books.dat");
                                return_up(name3);
                                cout<<"\nYou have successfully returned the book!!!!!!!"<<endl;
                                cout<<"If you want to borrow a new book you can go to our borrow section."<<endl;
                                break;
                                }
                                else
                                    cout<<"Either your record is not there or you are returning a wrong book."<<endl;
                               }
                               else
                               {
                                   cout<<"Please pay the fine."<<endl;
                               }
                                break;}
                        case 5:{int in;
                                int flag=0,temp=0;
                                cout<<"\nEnter your prn:";
                                cin>>in;
                                fstream fin("Student.dat",ios::binary|ios::in|ios::out);
                                while(fin.read((char*)&student,sizeof(student)))
                                {
                                    if(student.return_prn()==in)
                                    {
                                        flag=1;
                                        break;
                                    }
                                    else
                                        temp++;
                                }
                                if(flag==1)
                                {
                                    cout<<"Enter your new deatils:";
                                    long int pos=(temp)*sizeof(student);
                                    fin.seekp(pos);
                                    student.getdata();
                                    fin.write((char*)&student,sizeof(student));
                                    cout<<"Information modified successfully!!!"<<endl;
                                 }
                                 else
                                 {
                                     cout<<"Record not found"<<endl;
                                 }
                                 fin.close();
                                 break;}
                        case 6:exit(0);
                     }
                    }while(choice<7);
                    break;
                 }
          case 3:exit(0);
        }
    }while(x<4);
}

int main()
{
	cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"                                                                         WELCOME TO THE LIBRARY"<<endl;
    cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
    int x;
    do
    {
    	cout<<"\nHOW DO YOU WANT TO ENTER:"<<endl;
        cout<<"1.ADMIN\n2.STUDENT"<<endl;
        cin>>x;
        try
        {
        	if(x==1)
        	{
        		cout<<"*****************ENTERED AS AN ADMIN******************"<<endl;
        		admin_1();
        	}
        	else if(x==2)
        	{
        		cout<<"*****************ENTERED AS A STUDENT*****************"<<endl;
        		student_1();
        	}
        	else
        	{
        		throw(x);
        	}
        }
        catch(int invalid)
        {
        	cout<<"\nException caught"<<endl;
            cout<<"The input you gave is invalid"<<endl;
            cout<<"Please re-run the program and enter the correct input."<<endl;
            exit(0);
        }
    }while(x<3);
    return 0;
}




