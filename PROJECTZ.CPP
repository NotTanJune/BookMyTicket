#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<fstream>
#include<cstring>
#include<iomanip>
#include<cctype>
#include<string>
#include<limits>
#include<vector>

using namespace std;

// Minimal console helpers used throughout
static void clrscr()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

static void getch()
{
	cout.flush();
	// If a newline is pending, consume it; otherwise wait for an Enter
	if (cin.peek() == '\n') {
		cin.get();
	} else {
		string _tmp;
		getline(cin, _tmp);
	}
}

// Safe line reader for C-style buffers. Skips a pending newline and reads up to size-1 chars.
static void read_line(char* buf, size_t size)
{
	if (!buf || size == 0) return;
	// If previous formatted extraction left a newline, drop it
	if (cin.peek() == '\n') {
		cin.ignore();
	}
	cin.getline(buf, static_cast<std::streamsize>(size));
	if (cin.fail() && !cin.eof()) {
		// Input longer than buffer; clear the rest of the line
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}
int strcmpi(const char* str1, const char* str2) {
	while (*str1 && *str2) {
		char c1 = tolower(*str1);
		char c2 = tolower(*str2);
		if (c1 < c2) return -1;
		if (c1 > c2) return 1;
		str1++;
		str2++;
	}
	return tolower(*str1) - tolower(*str2);
}

// Prompt to update a C-string field; keep old value if user enters blank
void prompt_update_field(const char* label, char* field, size_t size)
{
	cout << "\n\t\t\t" << label << " [" << field << "]: ";
	cout.flush();
	string line;
	getline(cin, line);
	if (!line.empty()) {
		strncpy(field, line.c_str(), size - 1);
		field[size - 1] = '\0';
	}
}

void screen1();
void screen2();
void screen3();

// Class to represent a movie
class movies
{
    char movie_name[50],language[20],genre[30],format[10],lead_actor[30],lead_actress[30];

public:

    void getdata();

    void showdata()
    {
        cout<<"\n\t\t\tMovie name:"<<movie_name;
        cout<<"\n\t\t\tLanguage:"<<language;
        cout<<"\n\t\t\tGenre:"<<genre;
        cout<<"\n\t\t\tFormat:"<<format;
        cout<<"\n\t\t\tLead Actor:"<<lead_actor;
        cout<<"\n\t\t\tLead Actress:"<<lead_actress;
    }

    char *retmname()
    {
        return movie_name;
    }

};

void movies :: getdata()
{
	cout<<"\n\n";
	cout<<"\n\t\t\t\t*********";
	cout<<"\n\t\t\t\t DETAILS";
	cout<<"\n\t\t\t\t*********";
	cout<<"\n\n\n\t\t\tEnter the movie name:";
	read_line(movie_name, sizeof(movie_name));
	cout<<"\n\t\t\tEnter the language of the movie:";
	read_line(language, sizeof(language));
	cout<<"\n\t\t\tEnter the genre:";
	read_line(genre, sizeof(genre));
	cout<<"\n\t\t\tEnter the format [2D/3D/4D]:";
	read_line(format, sizeof(format));
	cout<<"\n\t\t\tEnter the name of lead actor:";
	read_line(lead_actor, sizeof(lead_actor));
	cout<<"\n\t\t\tEnter the name of lead actress:";
	read_line(lead_actress, sizeof(lead_actress));
	cout<<"\n";
}

movies m;

class moviehall
{	public:char hallname[20];
	char location[20];
	char timeAmovie[20];
	int Atottic;
	int Aticsold;
	char timeBmovie[20];
	int Btottic;
	int Bticsold;
	char timeCmovie[20];
	int Ctottic;
	int Cticsold;
	char timeDmovie[20];
	int Dtottic;
	int Dticsold;

	char seatsA[9][9];
	char seatsB[9][9];
	char seatsC[9][9];
	char seatsD[9][9];

	void seatData()
	{
		for(int i=0;i<9;i++)
			 for(int j=0;j<9;j++)
			 {
					seatsA[i][j]='X';
					seatsB[i][j]='X';
					seatsC[i][j]='X';
					seatsD[i][j]='X';
			 }
		Atottic = Btottic = Ctottic = Dtottic = 81;
		Aticsold = Bticsold = Cticsold = Dticsold = 0;
	}

	void getdata()
	{
		clrscr();
		cout<<"\n\n\n\n\n\n\t\t\tEnter the theatre name:";
	read_line(hallname, sizeof(hallname));
		cout<<"\n\t\t\tEnter the location of the theatre:";
	read_line(location, sizeof(location));
		cout<<"\n\t\t\tEnter the movie name 1:";
	read_line(timeAmovie, sizeof(timeAmovie));
		cout<<"\n\t\t\tEnter the movie name 2:";
	read_line(timeBmovie, sizeof(timeBmovie));
		cout<<"\n\t\t\tEnter the movie name 3:";
	read_line(timeCmovie, sizeof(timeCmovie));
		cout<<"\n\t\t\tEnter the movie name 4:";
	read_line(timeDmovie, sizeof(timeDmovie));
		seatData();
	 }

	 void showdata1()
	 {
		clrscr();
		cout<<"\n\t\t\tTheatre name:"<<hallname;
		cout<<"\n\t\t\tLocation:"<<location;
		cout<<"\n\t\t\tMovie name 1:"<<timeAmovie;
		cout<<"\n\t\t\tMovie name 2:"<<timeBmovie;
		cout<<"\n\t\t\tMovie name 3:"<<timeCmovie;
		cout<<"\n\t\t\tMovie name 4:"<<timeDmovie;
	 }

	 int ticleft(char time)
	 {
		switch(time)
		{
			case 'A' : return Atottic - Aticsold;
			case 'B' : return Btottic - Bticsold;
			case 'C' : return Ctottic - Cticsold;
			case 'D' : return Dtottic - Dticsold;
		}
		return 0;
	 }

	 const char* disptime(char time)
	 {
		switch(time)
		{
			case 'A' : return "10:00 A.M.";
			case 'B' : return "2:00 P.M.";
			case 'C' : return "5:00 P.M.";
			case 'D' : return "9:00 P.M.";
		}
		return "Unknown";
	 }

	 void showdata2(char time)
	 {
		cout<<"\n";
		cout<<setw(20)<<hallname<<setw(20)<<location<<setw(20)<<disptime(time)<<setw(15)<<ticleft(time)<<"\n";
	 }

	 void showdet()
	 {	cout<<"\n\n\t\t\tLocation:"<<location;
	 }

	 void reserveSeat(int x, int y, char time)
	 {
		switch(time)
		{
			case 'A': seatsA[x][y]='F';
					  Aticsold++;
					  break;
			case 'B': seatsB[x][y]='F';
					  Bticsold++;
					  break;
			case 'C': seatsC[x][y]='F';
					  Cticsold++;
					  break;
			case 'D': seatsD[x][y]='F';
					  Dticsold++;
					  break;
		}
	 }

	 int seatEmpty(int x, int y, char time)
	 {
		switch(time)
		{
			case 'A': if ( seatsA[x][y]=='X')
						return 1;
					  else
						return 0;
					  break;
			case 'B': if ( seatsB[x][y]=='X')
						return 1;
					  else
						return 0;
					  break;
			case 'C': if ( seatsC[x][y]=='X')
						return 1;
					  else
						return 0;
					  break;
			case 'D': if ( seatsD[x][y]=='X')
						return 1;
					  else
						return 0;
					  break;
		}
		return 0; // Default return
	 }

};

// DATA HANDLING FUNCTIONS FOR THE FILE MOVIE.DAT

// Function to append movie information to file
void app_mov()
{   ofstream f;
	f.open("movie.dat",ios::binary|ios::app);//opening the file
	if(!f)
	{	cout<<"\Error occured";
		getch();
		return;
	}
	movies m;

	while(1)
	{	//clrscr(); // Commented out to prevent screen clearing issues
		cout<<"\n";
		m.getdata();//taking in the data
		f.write((char*)&m,sizeof(m));//writing in the file
		
		char response;
		cout<<"\n\t\t     DO YOU WANT TO ENTER MORE MOVIES?[y/n]: ";
		cin >> response;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		if(response=='n' || response=='N')
			break;

	}
	f.close();//closing the file
}

// Function to display information about a specific movie
void disp1_mov()
{   clrscr();
    char name[20];
    cout<<"\n\n\n\n\n\t\t\tEnter the movie name you want to watch:";
    read_line(name, sizeof(name));
    ifstream fin;
    fin.open("movie.dat",ios::binary);
    if(!fin)
    {   cout<<"\nError in open ";
        getch();
        return;
    }
    movies m;
    int found=0;
    while(1)
    {   fin.read((char*)&m,sizeof(m));
        if(fin.eof())
            break;
        if(strcmpi(m.retmname(),name)==0)
        {   found=1;
            break;
        }
    }
    fin.close();
    if(found==0)
    {   cout<<"\n\nSORRY,our theatre isn't showing this movie at the moment.";
    }
    else
    {   m.showdata();
    }
    getch();
}

// Display information about all movies
void dispA_mov()
{
	clrscr();
	ifstream fin("movie.dat", ios::binary);
	if(!fin)
	{   cout<<"Error";
		getch();
		return;
	}
	vector<movies> list;
	movies m;
	while (fin.read((char*)&m, sizeof(m)))
		list.push_back(m);
	fin.close();

	if (list.empty())
	{
		cout<<"\n\n\t\tNo movies found.";
		getch();
		return;
	}

	int i = 0;
	while (true)
	{
		clrscr();
		cout<<"\n\n\n\n\n\n\t\t\t\t*************";
		cout<<"\n\t\t\t\tMovie details ("<< (i+1) <<" of "<< list.size() <<")";
		cout<<"\n\t\t\t\t*************";
		list[i].showdata();
		cout<<"\n\n\t\t[N]ext  [P]revious  [Q]uit : ";
		char ch; 
		cin>>ch; 
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		if (ch=='q' || ch=='Q') break;
		if ((ch=='n'||ch=='N')) { if (i < (int)list.size()-1) i++; }
		else if ((ch=='p'||ch=='P')) { if (i > 0) i--; }
		// Any other key repeats the same item
	}
}

// Function to modify movie information
void mod_mov()
{   clrscr();
    char name[20];
    cout<<"\n\n\n\n\n\t\t\tEnter the name of the movie: ";
    read_line(name, sizeof(name));

    fstream ifile;
    ifile.open("movie.dat",ios::binary|ios::in|ios::out);
    if(!ifile)
    {   cout<<"\nError in open";
        getch();
        return;
    }

    movies m1;
    int f=0;
    int recno=0;
    while(1)
    {
        ifile.read((char*)&m1,sizeof(m1));
        if(ifile.eof())
        break;
        if(strcmpi(m1.retmname(),name)==0)
        {
            f=1;
            cout<<"\n\n\t\t\tOLD DATA";
            m1.showdata();
            cout<<"\n\n\t\t\tENTER NEW DATA";
            m1.getdata();
            ifile.seekp(recno*sizeof(m1));
            ifile.write((char*)&m1,sizeof(m1));
        }
        recno++;
    }
    ifile.close();
    if(f==0)
    {   cout<<"\n\n\t\t\tRecord not found ";
    }
    else
    {       cout<<"\nRecord modification successfully made.";
    }
    getch();
}

// Function to delete a movie record
void del_mov()
{   clrscr();
    char name[20];
    cout<<"\n\n\n\n\n\t\t\tEnter the name of the movie to delete: ";
    read_line(name, sizeof(name));

    ifstream ifile;
    ifile.open("movie.dat",ios::binary);
    if(!ifile)
    {
        cout<<"Error in open ";
        getch();
        return;
    }

    ofstream ofile;
    ofile.open("temp.dat",ios::binary);
    movies m2;

    int found=0;
    while(1)
    {
        ifile.read((char*)&m2,sizeof(m2));
        if(ifile.eof())
        break;
        if(strcmpi(m2.retmname(),name)!=0)
        {
            ofile.write((char*)&m2,sizeof(m2));
        }
        else
        {

            found=1;
        }
    }
    ifile.close();
    ofile.close();
    remove("movie.dat");
    rename("temp.dat","movie.dat");
    if(!found)
        cout<<"\n\n\t\t\tRecord for deletion not found";
    else
        cout<<"\n\t\t\tData deleted successfully ";
    getch();
}

// DATA FILE HANDLING FUNCTIONS FOR THE FILE MOVIE1.DAT

// Function to append a theatre info to the file
void app_mov1()
{	clrscr();
	ofstream f;
	f.open("movie1.dat",ios::binary|ios::app);//opening the file
	if(!f)
	{	cout<<"\Error occured";
		getch();
		return;
	}
	moviehall mh;

	while(1)
	{	clrscr();
		cout<<"\n\n\t\t\t\t************";
		cout<<"\n\n\t\t\t\tHALL DETAILS ";
		cout<<"\n\n\t\t\t\t************";
		mh.getdata();//taking in the data
		f.write((char*)&mh,sizeof(mh));//writing in the file
		cout<<"\n\n\n\t\t\tDO YOU WANT TO ENTER MORE ?[y/n]";
		char a;
		cin>>a;
		cin.ignore(); // Consume the leftover newline character
		if(a=='n'||a=='N')
			break;
	}
	f.close();//closing the file
}

// Function to display a theatre info
void disp1_mov1()
{	clrscr();
    char name[20];
    cout<<"\n\n\n\n\n\t\t\tEnter the theatre name:";
    read_line(name, sizeof(name));
    ifstream fin;
    fin.open("movie1.dat",ios::binary);
    if(!fin)
    {   cout<<"\nError in open ";
        getch();
        return;
    }

    moviehall mh;
    int found=0;
    while(1)
    {   fin.read((char*)&mh,sizeof(mh));
        if(fin.eof())
        break;
        if(strcmpi(mh.hallname,name)==0)
        {   found=1;
            mh.showdata1();
        }
    }
    fin.close();
    if(found==0)
    {   cout<<"\n\nSORRY,this theatre doesn't exist or check the the spelling errors.";
    }
    getch();
}

// Function to display information about all movie halls
void dispA_mov1()
{	clrscr();
	ifstream fin;
	fin.open("movie1.dat",ios::binary);//opening the file
	if(!fin)
	{	cout<<"Error";
		getch();
		return;
	}
	moviehall mh;
	while(1)
	{	fin.read((char*)&mh,sizeof(mh));//reading the file
		if(fin.eof())
		break;
		mh.showdata1();//showing the data
		getch();
	}
	fin.close();//closing the file
}

// Function to modify theatre information
void mod_mov1()
{	clrscr();
    char name[20];
    cout<<"\n\n\n\n\n\t\t\tEnter the name of the movie theatre:";
    read_line(name, sizeof(name));

    fstream ifile;
    ifile.open("movie1.dat",ios::binary|ios::in|ios::out);
    if(!ifile)
    {   cout<<"\nError in open";
        getch();
        return;
    }

    moviehall mh;
    int f=0;
    while(1)
    {
        std::streampos before = ifile.tellg();
        ifile.read((char*)&mh,sizeof(mh));
        if(ifile.eof())
            break;
        if(strcmpi(mh.hallname,name)==0)
        {
            f=1;
            cout<<"\n\n\n\n\t\t\tOld data:";
            mh.showdata1();
            cout<<"\n\n\n\n\t\t\tEnter new theatre (press Enter to continue Enter in every field to keep previous value)";
            // Ensure no stray input is left before first getline
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            prompt_update_field("Theatre name", mh.hallname, sizeof(mh.hallname));
            prompt_update_field("Location", mh.location, sizeof(mh.location));
            prompt_update_field("Movie name 1", mh.timeAmovie, sizeof(mh.timeAmovie));
            prompt_update_field("Movie name 2", mh.timeBmovie, sizeof(mh.timeBmovie));
            prompt_update_field("Movie name 3", mh.timeCmovie, sizeof(mh.timeCmovie));
            prompt_update_field("Movie name 4", mh.timeDmovie, sizeof(mh.timeDmovie));
            // Overwrite the record we just read
            ifile.seekp(before);
            ifile.write((char*)&mh,sizeof(mh));
            ifile.flush();
            break;
        }
    }
    ifile.close();
    if(!f)
    {   cout<<"\n\n\t\t\tRecord not found ";
    }
    else
    {       cout<<"\n\t\t\tRecord modification successfully made.";
    }
    getch();
}

// Function to delete theatre information
void del_mov1()
{   clrscr();
    char name[20];
    cout<<"\n\n\n\n\n\t\t\tEnter the name of the theatre to delete: ";
    read_line(name, sizeof(name));

    ifstream ifile;
    ifile.open("movie1.dat",ios::binary);
    if(!ifile)
    {
        cout<<"\nError in open ";
        getch();
        return;
    }

    ofstream ofile;
    ofile.open("temp.dat",ios::binary);
    moviehall m2;

    int found=0;
    while(1)
    {
        ifile.read((char*)&m2,sizeof(m2));
        if(ifile.eof())
        break;
        if(strcmpi(m2.hallname,name)!=0)
        {
            ofile.write((char*)&m2,sizeof(m2));
        }
        else
        {
            found=1;
        }
    }
    ifile.close();
    ofile.close();
    remove("movie1.dat");
    rename("temp.dat","movie1.dat");
    if(!found)
        cout<<"\n\n\n\t\t\tRecord for deletion not found";
    else
        cout<<"\n\t\t\tData deleted successfully";
	getch();
}

// The Hall_det function.
// Prints the menu for manipulating theatre data.
void Hall_det()
{	clrscr();
	while(1)
	{       clrscr();
		cout<<"\n\n\n\t\t\t\tCHOOSE AN OPTION";
		cout<<"\n\t\t\t1.Add a theatre ";
		cout<<"\n\t\t\t2.Display one movie theatre information";
		cout<<"\n\t\t\t3.Display information about all movie halls";
		cout<<"\n\t\t\t4.Modify movie theatre information";
		cout<<"\n\t\t\t5.Delete the theatre record";
		cout<<"\n\t\t\t6.Previous page";
		cout<<"\n\t\t\t7.Exit";

		int c;
		cout<<"\n\t\t\tEnter your choice: ";
		cin>>c;
		// consume trailing newline so subsequent getline calls don't get skipped
		cin.ignore(numeric_limits<streamsize>::max(),'\n');

		switch(c)
		{
			case 1:app_mov1();
				   break;
			case 2:disp1_mov1();
				   break;
			case 3:dispA_mov1();
				   break;
			case 4:mod_mov1();
				   break;
			case 5:del_mov1();
				   break;
			case 6:screen3();
				   break;
			case 7:exit(0);
				   break;
		}
	}
}

// Function mov_dat.
// Prints menu for manipulating the movie data file.
void mov_dat()
{	clrscr();
	while(1)
	{	clrscr();
		cout<<"\n\n\n\t\t\t\tCHOOSE AN OPTION";
		cout<<"\n\t\t\t1.Add movie details ";
		cout<<"\n\t\t\t2.Display details of one movie";
		cout<<"\n\t\t\t3.Display details of all movies";
		cout<<"\n\t\t\t4.Modify a movie detail";
		cout<<"\n\t\t\t5.Delete the movie record";
		cout<<"\n\t\t\t6.Previous page";
		cout<<"\n\t\t\t7.Exit";

		int c;
		cout<<"\n\t\t\tEnter your choice: ";
		cin>>c;
		// consume trailing newline so first gets() in invoked functions reads properly
		cin.ignore(numeric_limits<streamsize>::max(),'\n');

		switch(c)
		{
			case 1:app_mov();
				   break;
			case 2:disp1_mov();
				   break;
			case 3:dispA_mov();
				   break;
			case 4:mod_mov();
				   break;
			case 5:del_mov();
				   break;
			case 6:screen3();
				   break;
			case 7:exit(0);
				   break;
		}
	}
}

// Function screen3 that allows the administrator to set up internal files.
// Option 1 deals with movie data.
// Option 2 deals with theatre data.
void screen3()
{	clrscr();
	cout<<"\n\n\n\n\n\t\t\tFor movie detail setup press 1";
	cout<<"\n\t\t\tFor theatre detail setup press 2 ";
	cout<<"\n\t\t\tPress 3 for the previous page";
	cout<<"\n\t\t\tPress 4 to exit ";
	cout<<"\n\t\t\tEnter:";
	int d;
	cin>>d;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	switch(d)
	{	case 1:mov_dat();
			   break;
		case 2:Hall_det();
			   break;
		case 3:screen2();
			   break;
		case 4:exit(0);
			   break;
		default:cout<<"\n\t\t\t\tINVALID CHOICE";
	}
}

// Function that displays the names of all halls running movie m
int mov_in_hall( char m[30] )
{
	ifstream fin;
	fin.open("movie1.dat",ios::binary);
	if(!fin)
	{	cout<<"\nError in open ";
		getch();
		return -1;
	}

	moviehall mh;
	int tics=0;
	int found=0;
	cout<<"\n*************************************************************************\n";
	cout<<setw(20)<<"THEATRE NAME"<<setw(20)<<"LOCATION"<<setw(20)<<"MOVIE TIME"<<setw(15)<<"TICKETS LEFT";
	cout<<"\n*************************************************************************";
	while(1)
	{	fin.read((char*)&mh,sizeof(mh));
		if(fin.eof())
		break;
		if(strcmpi(mh.timeAmovie,m)==0)
		{   found=1;
			mh.showdata2('A');
			tics+=mh.ticleft('A');
		}
		else if(strcmpi(mh.timeBmovie,m)==0)
		{   found=1;
			mh.showdata2('B');
			tics+=mh.ticleft('B');
		}
		else if (strcmpi(mh.timeCmovie,m)==0)
		{	found=1;
			mh.showdata2('C');
			tics+=mh.ticleft('C');
		}
		else if (strcmpi(mh.timeDmovie,m)==0)
		{	found=1;
			mh.showdata2('D');
			tics+=mh.ticleft('D');
		}
	}
	fin.close();
	if(found==0)
	{	cout<<"\n\nSORRY,no theatre is currently running this movie.";
		return -1;
	}
	else if ( tics==0)
	{   cout<<"\n\nSORRY,no tickets available for this movie.";
		return -1;
	}
	else return 1;
}


void debcred()
{   clrscr();
    // Clear any pending newline from previous numeric input
    if (cin.peek()=='\n') cin.ignore(numeric_limits<streamsize>::max(),'\n');
    char f[10];
    cout<<"\n\n\n\n\t\t\tEnter the name of bank:";
    read_line(f, sizeof(f));
    int y;
    cout<<"\n\t\t\tEnter the card number:";
    cin>>y;
    // Clear the newline after the number
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    char t[10];
    cout<<"\n\t\t\tEnter the expiration date (DD/MM/YY):";
    read_line(t, sizeof(t));
    char o[10];
    cout<<"\n\t\t\tEnter the password:";
    read_line(o, sizeof(o));
    cout<<"\n\n\t\t\tSHOPPER DETAILS:";
    char u[20];
    cout<<"\n\n\t\t\tEnter your name:";
    read_line(u, sizeof(u));
    char g[20];
    cout<<"\n\t\t\tEnter the email address:";
    read_line(g, sizeof(g));
    cout<<"\nPress enter to continue";
    clrscr();
    cout<<"\n\n\n\n\n\n\n\t\tYour ticket is booked.Thanks for using our website!";
    getch();
    screen1();
}

void netbank()
{   clrscr();
    // Clear any pending newline from previous numeric input
    if (cin.peek()=='\n') cin.ignore(numeric_limits<streamsize>::max(),'\n');
    char l[10];
    cout<<"\n\n\n\n\t\t\tEnter your bank:";
    read_line(l, sizeof(l));
    char g[20];
    cout<<"\n\t\t\tEnter your ID:";
    read_line(g, sizeof(g));
    char r[20];
    cout<<"\n\t\t\tEnter the password:";
    cin>>r;
    cout<<"\n\n\t\t\tPress any key to continue";
    getch();
    clrscr();
    cout<<"\n\n\n\n\n\n\n\t\tYour ticket is booked.Thanks for using our website!";
    getch();
    screen1();
}

// Function to display bill details and take user payment
void payment(int n)
{	clrscr();
	int t,gst,tot;
	cout<<"\n\n\n\n\n\t\t\tBill\n";
	t=150*n;
	cout<<"\t\t\tTickets: Rs. 150*"<<n<<"="<<t;
	cout<<"\n\t\t\tService charge: Rs. 50";
	gst=t*15/100;
	cout<<"\n\t\t\tGST(15%) = Rs. "<<gst;
	tot=t+gst+50;
	cout<<"\n\t\t\tSub Total: Rs. "<<tot;
	cout<<"\n\t\t\t***************************";
	cout<<"\n\n\t\t\tHow would you like to pay?";
	cout<<"\n\t\t\t1.Net Banking";
	cout<<"\n\t\t\t2.Debit/Credit card";
	cout<<"\n\t\t\tEnter:";
	int g;
	cin >> g;
	while (true)
	{
		switch(g)
		{
			case 1: netbank(); return;
			case 2: debcred(); return;
			default:
				cout << "\n\t\t\tInvalid choice. Try again: ";
				getch();
				cin.clear(); // Clear the error state
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
				cin >> g; // Prompt for input again
		}
	}
}

// Function to update the seat matrix corresponding to movie theatre hall
// and show time t for seat (i,j) in the movie1.dat file
void updateSeat(char hall[20], char t, int i, int j)
{
	int a=0,recno=0;
	fstream s;
	s.open("movie1.dat",ios::binary|ios::in|ios::out);
	if(!s)
	{	cout<<"\nError in open ";
		getch();
		return;
	}
	moviehall n;
	while (1)
	{
		s.read((char*)&n,sizeof(n));
		if ( s.eof() )
			break;
		if ( strcmpi(n.hallname, hall) == 0 )
		{
			n.reserveSeat(i,j,t);
			s.seekp(recno*sizeof(n));
			s.write((char*)&n,sizeof(n));
		}
		recno++;
	}
	s.close();
}

// Searches for the record corresponding to hall in movie1.dat
// Prints the seat matrix corresponding to the timing t
// Asks the user for seat numbers to book and updates the movie1.dat file
// Preceeds to invoke payment()
void seats(char hall[20], char t)
{	clrscr();

	ifstream s;
	s.open("movie1.dat",ios::binary);
	if(!s)
	{	cout<<"\nError in open ";
		getch();
		return;
	}
	moviehall n;
	while(1)
	{
		s.read((char*)&n,sizeof(n));
		if(s.eof())
			break;
		if ( strcmpi(n.hallname, hall) == 0 )
		{
				break;
		}
	}
	s.close();

	cout<<"\n'X'-Empty seats";
	cout<<"\n'F'-Booked seats";
	cout<<"\n";
	cout<<"\n";
	cout<<"\n\t\t         *********SCREEN HERE*********";
	cout<<"\n\n\t\t       1   2   3   4   5   6   7   8   9";
	for(int r=0;r<9;r++)
	{   cout<<"\n\t\t    ";
		for(int c=0;c<9;c++)
		{
			if(c==0)
			{
				switch(t)
				{
					case 'A':cout<<r+1<<"  "<<n.seatsA[r][c]<<"   ";
						 break;
					case 'B':cout<<r+1<<"  "<<n.seatsB[r][c]<<"   ";
						 break;
					case 'C':cout<<r+1<<"  "<<n.seatsC[r][c]<<"   ";
						 break;
					case 'D':cout<<r+1<<"  "<<n.seatsD[r][c]<<"   ";
						 break;
				}
			}
			else
			{
				switch(t)
				{
					case 'A':cout<<n.seatsA[r][c]<<"   ";
							 break;
					case 'B':cout<<n.seatsB[r][c]<<"   ";
							 break;
					case 'C':cout<<n.seatsC[r][c]<<"   ";
							 break;
					case 'D':cout<<n.seatsD[r][c]<<"   ";
							 break;
				}
			}
		}
	}
	cout<<"\n";
	cout<<"\nHow many seats do you want? ";
	int e;
	cin>>e;
	int y,w,x;
	for(int i=0;i<e;i++)
	{	cout<<"\nEnter row no. for ticket "<<i+1<<":";
		cin>>y;
		cout<<"\nEnter column no. for ticket "<<i+1<<":";
		cin>>w;
		if ( n.seatEmpty(y-1,w-1,t) )
		{
			updateSeat(hall,t,y-1,w-1);
			n.reserveSeat(y-1,w-1,t);
		}
		else
		{
			cout<<"\nThis seat is booked try again !!!";
			i--;
		}
	}
	payment(e);
	exit(-1);
}

// Asks the user to select the moviename, hall and timing
// and then invokes seats()
void bookall()
{   moviehall mh;
    cout<<"\n\n\n\t\t\tEnter the name of the movie you want to watch:";
    char mov[30];
    if (cin.peek()=='\n') cin.ignore();
    read_line(mov, sizeof(mov));
    int r = mov_in_hall(mov);
    if  ( r== -1 )
    {
        cout<<"\n\t\t\tPress any key to go back ";
        getch();
        screen2();
    }
    cout <<"\n\t\t\tDo you wish to proceed to ticket booking [y/n] ";
    char ch;
    cin >> ch;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    if  ( ch == 'n' || ch == 'N' )
    {
        cout<<"\n\t\t\tPress any key to go back ";
        getch();
        screen2();
    }
    cout<<"\n\n\t\t\tEnter the movie theatre you want to watch in: ";
    char hall[20];
    read_line(hall, sizeof(hall));
    cout<<"\n\n\t\t\tEnter the movie timing ";
    cout<<"\n\t\tA. 10:00 A.M.";
    cout<<"\n\t\tB.  2:00 P.M";
    cout<<"\n\t\tC.  5:00 P.M";
    cout<<"\n\t\tD.  9:00 P.M";
    cout<<"\n\n\t\tEnter A/B/C/D : ";
    char t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"\n\n\t\t\tPlease enter any key to book your tickets";
    seats(hall,t);
    getch();
}

// Function that displays the names of all currently running movies
// and then invokes bookall()
void cur_show()
{	clrscr();
	ifstream fin;
	fin.open("movie.dat",ios::binary);//opening the file
	if(!fin)
	{	cout<<"Error";
		getch();
		return;
	}
	cout<<"\n\n\n\n\t\t\t\t*****************";
	cout<<"\n\t\t\t\tCURRENTLY SHOWING";
	cout<<"\n\t\t\t\t*****************";
	movies m;
	int i=0;
	while(1)
	{	fin.read((char*)&m,sizeof(m));//reading the file
		if(fin.eof())
		break;
		cout<<"\n\t\t\t"<<i+1<<")";
		cout<<m.retmname();//showing the data
		getch();
		i++;
	}
	fin.close();
	bookall();
}

// The book_tic function.
// Invokes cur_show() if the user wishes to book tickets.
void book_tic()
{	clrscr();
	cout<<"\n\n\n\n\t\t\t1.Currently showing ";
	cout<<"\n\t\t\t2.Previous page";
	cout<<"\n\t\t\t3.Exit";
	cout<<"\n\n\t\t\tEnter your choice: ";
	int a;
	cin>>a;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	switch(a)
	{	case 1:cur_show();
			   break;
		case 2:screen2();
			   break;
		case 3:exit(0);
			   break;
		default:cout<<"\n\nINVALID CHOICE";
			getch();
			exit(0);
	}
}

// The help function.
// Tells the user how to use the software.
// And where to reach in case of complaints.
void help()
{	clrscr();
	cout<<"\n\n\n\n\t\t\t***********";
	cout<<"\n\t\t\tHELP CENTRE";
	cout<<"\n\t\t\t***********";
	cout<<"\n\n\tThis software allows you to book movie tickets.";
	cout<<"\n\tTo book movie tickets use option 2.";
	cout<<"\n\tOption 1 is for the administrator to set up their internal databases.";
	char a[20];
	cout<<"\n\n\t\tEnter your name:";
    read_line(a, sizeof(a));
	char l[100];
	cout<<"\n\n\t\tEnter your complaint:";
    read_line(l, sizeof(l));
	cout<<"\n\n\t\tTHANK YOU FOR LETTING US KNOW YOUR PROBLEM";
	cout<<"\n\n\t\tCONTACT US:bookmyticket@gmail.com";
	cout<<"\n\n\t\tphone:011-2345667";
	getch();
	screen1();
}

// The screen2 function
// Prints the main menu
void screen2()
{
	clrscr();
	cout<<"\n\n\n\n\n\t\t\t\tChoose one option";
	cout<<"\n\n\t\t\t1.Setup database";
	cout<<"\n\t\t\t2.Book movie tickets";
	cout<<"\n\t\t\t3.Help ";
	cout<<"\n\t\t\t4.Exit ";
	cout<<"\n\n\t\t\tEnter your choice [1/2/3/4]:";

	int c;
	cin>>c;
	// clear newline so that subsequent string inputs aren't skipped
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	switch(c)
	{	case 1:screen3();
			   break;
		case 2:book_tic();
			   break;
		case 3:help();
			   break;
		case 4:cout<<"\n\n\t\t\t****************************";
			   cout<<"\n\t\t\tThanks for using our software ";
			   cout<<"\n\t\t\t******************************";
			   getch();
			   exit(0);
			   break;
		default:cout<<"\nInvalid choice ";
	}
}

// The screen1 function
// Prints the first screen and invokes screen2
void screen1()
{
	clrscr();
	cout<<"\n\n\n\n\n\n\n\n\t\t\t       BOOK MY TICKET";
	cout<<"\n\n\n\n\t\t\t  press any key to continue ";
	getch();
	screen2();
}

// The main function.
// Invokes screen1
int main()
{
	clrscr();
	screen1();
	return 0;
}