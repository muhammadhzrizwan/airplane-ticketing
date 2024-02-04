#include <iostream>
 #include <fstream>
 #include <conio.h>
 using namespace std;
 class file{
 public:
 bool login(string id,string p){
 string s;fstream f;
 f.open("file.txt",ios::in);
 while(!f.eof()){
 getline(f,s);
 if(s=="costumer`"){
 getline(f,s);
 getline(f,s);cout<<s;
 if(s==id){
 getline(f,s);cout<<s;
 if(s==p){return 1;}
 else{return 0;}}}}
 return 0;}
 void add(string s){
 fstream f;f.open("file.txt",ios::app);
 f<<"\n"<<s;
 f.close();}
 bool new_ticket(int h,string p,string id){
 int v=0;string s,str="ticket`\n"+id+"\n";fstream g;
 g.open("file.txt",ios::in);
 while(!g.eof()){
 getline(g,s);
 if(s=="flight`"){v++;}
 if(v==h){
 for(int w=0;w<4;w++){
 getline(g,s);
 str=str+s+"\n";}
 add(str);return 1;}}
 g.close();
 cout<<"\nPlease enter a valid flight number\n";return 0;}
 void view_all_flights(){
 string s;int c=1;
 fstream f;f.open("file.txt",ios::in);
 while(!f.eof()){
 if(s=="flight`"){
 getline(f,s);
 cout<<"Data of flight No. "<<c<<" :\n\n";c++;
 cout<<"Flight Service : "<<s<<"\n";
 getline(f,s);
 cout<<"Flight number : "<<s<<"\n";
 getline(
 .open("file.txt",ios::in);
cout<<"From "<<s;
 getline(f,s);
 cout<<" To "<<s<<"\n";
 cout<<endl;}
 getline(f,s);}}
 void cancel_flight(string id,int i){
 string s,o="";int n=0,t=0;
 fstream f;
 f.open("file.txt",ios::in);
 while(!f.eof()){
 getline(f,s);t++;
 if(s=="ticket`"){
 getline(f,s);
 if(s==id){n++;
 if(n==i){break;}}}}
 f.close();
 f.open("file.txt",ios::in);
 for(int k=0;k<t-2;k++){
 getline(f,s);
 o=o+s+"\n";}
 for(int l=0;l<7;l++){getline(f,s);}
 while(!f.eof()){
 getline(f,s);
 o=o+s+"\n";}
 f.close();
 f.open("file.txt",ios::out);
 f<<o;
 f.close();}
 void view_ticket(string id){
 string s;int x=1,g=0;
 fstream f;f.open("file.txt",ios::in);
 while(!f.eof()){
 getline(f,s);
 if(s=="ticket`"){
 getline(f,s);
 if(s==id){g=1;
 cout<<"Details of your Ticket No. "<<x;x++;
 getline(f,s);
 cout<<"\n\n________________________________________________________";
 cout<<"\nName of servive : "<<s;getline(f,s);
 cout<<"\n\nFlight # "<<s;getline(f,s);
 cout<<"\n\nFlight :\nFrom "<<s;getline(f,s);
 cout<<"  To "<<s;getline(f,s);cout<<endl;
 cout<<"________________________________________________________\n\n";}}}
 if(g==0){cout<<"\n\nSorry you don't have any tickets yet!\n";}
 f.close();}
 };
class person{
 string n,id,pa;
 public:
 friend class manager;
 friend class costumer;
 bool login(){
 l:
 system("cls");char c;
 string i,p;file f;bool b;
 cout<<"Enter your ID number : ";getline(cin,i);
 cout<<"Enter password :";getline(cin,p);
 b=f.login(i,p);
 if(b==1){id=i;pa=p;return 1;}
 else if(b==0){cout<<"/nWrong ID or password !\nPress 0 to return & any other key 
to try again\n";c=getch();
 if(c=='0'){return 0;}
 goto l;}}};
 class manager:public person{
 public:
 bool login(){
 l:
 system("cls");
 string i,p;char c;
 cout<<"Enter your ID number : ";getline(cin,i);
 cout<<"Enter password :";getline(cin,p);
 if(i=="Shimza"&&p=="qwerty123"){return 1;}
 else{cout<<"/nWrong ID or password !\nPress 0 to return & any other key to try 
again\n";c=getch();
 if(c=='0'){return 0;}
 goto l;}}
 void create_flight(){
 system("cls");
 string na,nu,fr,to,str;file f;
 cout<<"Enter flight's Data \n";
 cout<<"Name : ";getline(cin,na);
 cout<<"Number : ";getline(cin,nu);
 cout<<"From : ";getline(cin,fr);
 cout<<"To : ";getline(cin,to);
 str="flight`\n"+na+"\n"+nu+"\n"+fr+"\n"+to+"\n";
 f.add(str);
 cout<<"\nFlight created successfully!\nPress any key to return\n";getch();}
 void view_flights(){
 system("cls");file f;
 f.view_all_flights();
 cout<<"\n\nPress any key to return\n";getch();}
 };
class costumer:public person{
 public:
 void signup(){
 system("cls");
 string n,i,p,str;file f;
 cout<<"Enter your name : ";getline(cin,n);
 cout<<"Enter your ID : ";getline(cin,i);
 cout<<"Create a password : ";getline(cin,p);
 str="costumer`\n"+n+"\n"+i+"\n"+p+"\n";
 f.add(str);
 cout<<"\nAccount created successfully!\nPress any key to return\n";getch();}
 void New_ticket(){
 n:
 system("cls");
 int i;string p;file f;
 f.view_all_flights();
 cout<<"\n\nChoose one of given flights!\nEnter number :";cin>>i;
 system("cls");
 cout<<"Enter number of passengers : ";cin>>p;
 bool bo=f.new_ticket(i,p,id);
 if(bo==0){getch();goto n;}
 else if(bo==1){cout<<"\nTicket created successfully!\nPress any key to 
return\n";getch();}}
 void View_ticket(){
 system("cls");file f;
 f.view_ticket(id);
 cout<<"\n\nPress any key to return\n";getch();}
 void Cancel_ticket(){
 system("cls");file f;int i;
 f.view_ticket(id);
 cout<<"\nWhich flight do you want to cancel ?\nEnter Number : ";cin>>i;
 f.cancel_flight(id,i);
 cout<<"\nTicket cancelled successfully!\nPress any key to return\n";getch();}};
 bool structure(){
 bool x=0,y=0;string err;manager ma;costumer cu;
 start:
 system("cls");
 if(y==0){cout<<"Assalam-Alaikum!\nWelcome to Shimza online ticket booking 
system\n";y=1;}
 char c;
 cout<<"What do you want to do?\n1. Login as manager\n2. Use costumer 
services\n3. Exit\n\nPress Number\n";
 if(x==1){cout<<err<<"\n";x=0;}
 c=getch();system("cls");
 if(c=='1'&&ma.login()==1){
bool x1=0; string err1;
 mstart:
 system("cls");
 char c1;
 cout<<"Welcome Respected manager!\nChoose one of following:\n1. Create 
Flight\n2. View all Flights\n3. Logout\n\nPress Number\n";
 if(x1==1){cout<<err1<<"\n";x1=0;};
 c1=getch();
 if(c1=='1'){
 ma.create_flight();
 goto mstart;}
 else if(c1=='2'){
 ma.view_flights();
 goto mstart;}
 else if(c1=='3'){cout<<"\n\nLogging out ...";
 goto start;}
 else{err1="Only numeric digits (1-3) are valid!";x1=1;
 goto mstart;}}
 else if(c=='2'){
 bool x2=0; string err2;
 cstart:
 system("cls");
 char c2;
 cout<<"Welcome dear costumer!\nChoose one :\n1. Login\n2. Signup\n3. 
Return\n\nPress Number\n";
 if(x2==1){cout<<err2<<"\n";x2=0;}
 c2=getch();system("cls");
 if(c2=='1'&&cu.login()==1){
 bool x21=0; string err21;
 clstart:
 system("cls");
 char c21;
 cout<<"Choose one :\n1. Buy new ticket\n2. View list of my tickets\n3. Cancel 
tiket\n4. Logout\n\nPress Number\n";
 if(x21==1){cout<<err21<<"\n";x21=0;}
 c21=getch();
 if(c21=='1'){
 cu.New_ticket();
 goto clstart;}
 else if(c21=='2'){
 cu.View_ticket();
 goto clstart;}
 else if(c21=='3'){
 cu.Cancel_ticket();
 goto clstart;}
 else if(c21=='4'){cout<<"\n\nLogging out ...";
 goto cstart;}
 else{err21="Only numeric digits (1-4) are valid!";x21=1;
 goto clstart;}}
 else if(c2=='2'){
cu.signup();
 goto cstart;}
 else if(c2=='3'){cout<<"\n\nReturning ...";
 goto start;}
 else{err2="Only numeric digits (1-3) are valid!";x2=1;
 goto cstart;}}
 else if(c=='3'){system("cls");cout<<"\n\nAllah Hafiz!\nThanks for using our 
services.\nExiting ...";
 system("cls");return 0;}
 else{err="Only numeric digits (1-3) are valid!";x=1;
 goto start;}}
 int main(){
 structure();
 return 0;}