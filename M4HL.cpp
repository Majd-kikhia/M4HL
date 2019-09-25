#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <conio.h>

using namespace std;

int choice = 0;
int login_choice = 0;
long long confirm = -1;

struct account
{
	vector <int> all_walking;
	vector <int> all_running;
	vector <int> all_bicycling;
	vector <int> all_push_up;

	account()
	{
		all_walking.clear();
		all_running.clear();
		all_bicycling.clear();
		all_push_up.clear();
	}
};


struct data_project
{
	string login_name = "";
	string login_password = "";
	vector <string> all_names;
	vector <string> all_passowrd;
	vector <int> all_high;
	vector <int> all_wieght;
	vector <int> all_aim_wieght;
	account user[1000005];
	int aim_wieght;
	bool check = false;
	int rate = -1;
	data_project()
	{
  		 login_name = "";
		 login_password = "";
		 all_names.clear();
		 all_passowrd.clear();
		 all_high.clear();
		 all_wieght.clear();
		 all_aim_wieght.clear();
		 
		 aim_wieght = 0;
	}

	void main_page();
	void sign_up();
	void login();
	void get_name(string s);
	bool is_correct_name(string s);
	bool is_correct_password(string s);
	bool is_correct_name_login(string s);
	bool is_correct_password_login(string s);
	void login_page();
	void add_sport();
	void my_sport();
	void change_my_information();
	void rating();
	//int exit_project();

};

data_project user;

void data_project::main_page()
{
	cout << "welcome to M4HL" << endl << endl;
	cout << "please make a choice" << endl;
	cout << endl;
	cout << "1) sign up" << endl
		<< "2) login" << endl
		<< "3) exit app" << endl;

	cout << "your choice is: ";
	cin >> choice;
	while (choice < 1 || choice >3)
	{
		cout << "sorry choice in range from 1 to 3" << endl;
		cout << "your choice is: ";
		cin >> choice;
	}
	cout << endl;
	if (choice == 1)
		sign_up ();

	if (choice == 2)
		login();

	if (choice == 3)
		exit(0);


}

void  data_project::sign_up()
{
	int hafez = 0;
	string name = "";
	string password = "";
	char a[20];
	float high = 0.0;
	int wieght = 0;

	

	cout << "plesae wrtie your name " << endl;
	cout << "you can use letters and dots" << endl;
	cout << "your name is: ";
	
	cin >> name;
	while (1)
	{
		if (!(is_correct_name(name)))
		{
			cout << "Sorry something wrong ... try again" << endl;
			cout << "your name is: ";
			cin >> name;
		}
		else
			
			break;
	}

	cout << endl;
	cout << "please write a password" << endl;
	cout << "Use 8 or more characters using a combination of letters, numbers, and symbols" << endl;
	cout << "your password is: ";
	cin >> password;
	while (1)
	{
		if (!is_correct_password(password))
		{
			cout << "Sorry something wrong... try again" << endl;
			cout << "your password is: ";
			cin >> password;
		}
		else 
			break;
	}

	cout << endl;
	cout << "write your high in meters" << endl;
	cout << "your high is: ";
	cin >> high;
	while (1)
	{
		if (high < 1.50 || high >2.0)
		{
			cout << "sorry something wrong ... try again" << endl;
			cout << "your high is: ";
			cin >> high;
		}

		else
			break;
	}

	cout << endl;

	cout << "enter your wieght " << endl;
	cout << "your wieght is: ";
	cin >> wieght;
	cout << endl;
	cout << "Please write down the weight you aspire to : " << endl;
	cin >> aim_wieght;
	
	cout << endl << endl ;
	cout << "Your account has been successfully registered" << endl << endl;
	
	all_names.push_back(name);
	all_passowrd.push_back(password);
	all_high.push_back(high);
	all_wieght.push_back(wieght);
	all_aim_wieght.push_back(aim_wieght);

	main_page();


}



bool data_project::is_correct_name(string s)
{
	for (int i = 0 ; i < s.size() ; i++)
	{
		if (isalpha(s[i]) || s[i]=='.')
			continue;
		else
			return false;
		return true;

	}

}

bool data_project::is_correct_password(string s)
{
	if (s.size() < 8)
		return false;
	for (int i = 0; i < s.size(); i++)
	{
		if (isalnum(s[i]) || s[i] == '.')
			continue;
		else
			return false;
		return true;

	}


}

void data_project::login()
{
	
	cout << "please enter your name : ";
	cin >> login_name;

	cout << "please enter your password : ";
	cin >> login_password;

	while (1)
	{
		if (!is_correct_name_login(login_name))
		{
			cout << "Sorry ... your name is wrong , try again" << endl;
			cout << "enter your name : ";
			cin >> login_name;

			cout << "enter your password : ";
			cin >> login_password;

		}
		else
			break;
	}
	
	while (1)
	{
		if (!is_correct_password_login(login_password))
		{
			cout << "Sorry ... your password is wrong , try again" << endl;
			cout << "enter your password : ";
			cin >> login_password;
		}
		else
			break;
	}
	
	login_page();


}

void data_project::login_page()
{
	cout << "                 welcome " << login_name << endl << endl;
	cout << "please make a choice : " << endl << endl;
	cout << "1) Add sport.                              your weight is : " << all_wieght[confirm] << endl;
	cout << "2) My sport.                               your aim weight is : " << all_aim_wieght[confirm] << endl;
	cout << "3) Change my informations              " << endl;
	cout << "4) Rating  " << endl;
	cout << "5) exit account" << endl << endl;

	cout << "your choice is : ";
	cin >> login_choice;

	while (login_choice < 1 || login_choice >5)
	{
		cout << "sorry choice in range from 1 to 5" << endl;
		cout << "your choice is: ";
		cin >> login_choice;
	}


	if (login_choice == 1)
	{
		add_sport();
	}
	
	if (login_choice == 2)
	{
		my_sport();
	}
	
	if (login_choice == 3)
	{
		change_my_information();
	}

	if (login_choice == 4)
	{
		rating();
	}

	if (login_choice == 5)
	{
		main_page();
	}
}

void data_project::add_sport()
{
	int add_choice = -1;
	int walking = -1;
	int running = -1;
	int bicycling = -1;
	int pushup = -1;

	cout << endl;
	cout << "Choose the type of sport : " << endl;
	cout << "1) walking " << endl;
	cout << "2) running" << endl;
	cout << "3) bicycling" << endl;
	cout << "4) push up" << endl;
	cout << "5) back" << endl;

	cout << endl;
	cout << "your choice is : ";
	cin >> add_choice;

	while (add_choice < 1 || add_choice >5)
	{
		cout << "sorry choice in range from 1 to 5" << endl;
		cout << "your choice is: ";
		cin >> add_choice;
	}

	if (add_choice == 1)
	{	
		
		cout << "Write how many kilometers you walked" << endl;
		cin >> walking;
		user[confirm].all_walking.push_back(walking);
		add_sport();
	}

	if (add_choice == 2)
	{
		cout << "Write how many kilometers you running" << endl;
		cin >> running;
		user[confirm].all_running.push_back(running);
		add_sport();
	}

	if (add_choice == 3)
	{
		cout << "Write how many kilometers you bicycling" << endl;
		cin >> bicycling;
		user[confirm].all_bicycling.push_back(bicycling);
		add_sport();
	}

	if (add_choice == 4)
	{
		cout << "Write down how many times you had the push-up exercise" << endl;
		cin >> pushup;
		user[confirm].all_push_up.push_back(pushup);
		add_sport();
	}

	if (add_choice == 5)
	{
		login_page();

	}
}

void data_project::my_sport()
{
	int my_choice = -1;
	cout << "please make a choice : " << endl << endl;
	cout << "1) last day " << endl;
	cout << "2) last week " << endl;
	cout << "3) last month " << endl;
	cout << "4) last year " << endl;
	cout << "5) back" << endl;
	cout << endl;

	cout << "your choice is : ";
	cin >> my_choice;
	while (my_choice < 1 || my_choice >5)
	{
		cout << "sorry choice in range from 1 to 5" << endl;
		cout << "your choice is: ";
		cin >> my_choice;
	}

	if (my_choice == 1)
	{
		if (user[confirm].all_walking.size() == 0)
		{
			cout << "You never walked" << endl;
		}
		else
		{
			cout << "You walked : " << user[confirm].all_walking[user[confirm].all_walking.size() - 1] << endl;
		}

		if (user[confirm].all_running.size() == 0)
			cout << "you never ran" << endl;

		else
			cout << "You run : " << user[confirm].all_running[user[confirm].all_running.size() - 1] << endl;

		if (user[confirm].all_bicycling.size() == 0)
			cout << "You never drive a bike" << endl;

		else 
			cout << "You bicycled : " << user[confirm].all_bicycling[user[confirm].all_bicycling.size() - 1] << endl;

		if (user[confirm].all_push_up.size() == 0)
			cout << "You never did push-ups" << endl;

		else 
			cout << "You did push-ups : " << user[confirm].all_push_up[user[confirm].all_push_up.size() - 1] << endl;

		my_sport();
	}

	if (my_choice == 2)
	{
		long long my_walking = 0;
		long long my_running = 0;
		long long my_b = 0;
		long long my_push = 0;

		if (user[confirm].all_walking.size() < 7)
			cout << "You did not complete the week in walking" << endl;

		else
		{
			for (int i = user[confirm].all_walking.size() - 1; i > user[confirm].all_walking.size() - 8; i--)
			{
				my_walking += user[confirm].all_walking[i];
			}
			cout << "You walked : " << my_walking << endl;
		}

		if (user[confirm].all_running.size() < 7)
			cout << "You did not complete the week in running" << endl;

		else
		{
			for (int i = user[confirm].all_running.size() - 1; i > user[confirm].all_running.size() - 8; i--)
			{
				my_running += user[confirm].all_running[i];
			}
			cout << "You walked : " << my_running << endl;
		}

		if (user[confirm].all_bicycling.size() < 7)
			cout << "You did not complete the week in bicycling" << endl;

		else
		{
			for (int i = user[confirm].all_bicycling.size() - 1; i > user[confirm].all_bicycling.size() - 8; i--)
			{
				my_b += user[confirm].all_bicycling[i];
			}
			cout << "You walked : " << my_b << endl;
		}

		if (user[confirm].all_push_up.size() < 7)
			cout << "You did not complete the week in push_up exercises" << endl;

		else
		{
			for (int i = user[confirm].all_push_up.size() - 1; i > user[confirm].all_push_up.size() - 8; i--)
			{
				my_push += user[confirm].all_push_up[i];
			}
			cout << "You walked : " << my_push << endl;
		}
		my_sport();
	}

	if (my_choice == 3)
	{
		long long my_walking = 0;
		long long my_running = 0;
		long long my_b = 0;
		long long my_push = 0;

		if (user[confirm].all_walking.size() < 30)
		{
			cout << "You did not complete the month in walking" << endl;
		}
		
		else
		{
			for (int i = user[confirm].all_walking.size() - 1; i > user[confirm].all_walking.size() - 31; i--)
			{
				my_walking += user[confirm].all_walking[i];
			}
			cout << "You walked : " <<my_walking << endl;
		}

		if (user[confirm].all_running.size() < 30)
		{
			cout << "You did not complete the month in running" << endl;
		}

		else
		{
			for (int i = user[confirm].all_running.size() - 1; i > user[confirm].all_running.size() - 31; i--)
			{
				my_running += user[confirm].all_running[i];
			}
			cout << "You run : " <<my_running << endl;
		}

		if (user[confirm].all_bicycling.size() < 30)
		{
			cout << "You did not complete the month in bicycling" << endl;
		}

		else
		{
			for (int i = user[confirm].all_bicycling.size() - 1; i > user[confirm].all_bicycling.size() - 31; i--)
			{
				my_b += user[confirm].all_bicycling[i];
			}
			cout << "You bicycled : " <<my_b << endl;
		}
		if (user[confirm].all_push_up.size() < 30)
			cout << "You did not complete the month in push_up exercises" << endl;

		else
		{
			for (int i = user[confirm].all_push_up.size() - 1; i > user[confirm].all_push_up.size() - 31; i--)
			{
				my_push += user[confirm].all_push_up[i];
			}
			cout << "you did push ups : " <<my_push << endl;

		}
		my_sport();
	}

	if (my_choice == 4)
	{
		long long my_walking = 0;
		long long my_running = 0;
		long long my_b = 0;
		long long my_push = 0;

		if (user[confirm].all_walking.size() < 365)
		{
			cout << "You did not complete the year in walking" << endl;
		}

		else
		{
			for (int i = user[confirm].all_walking.size() - 1; i > user[confirm].all_walking.size() - 366; i--)
			{
				my_walking += user[confirm].all_walking[i];
			}
			cout << "You walked : " << my_walking << endl;
		}

		if (user[confirm].all_running.size() < 365)
		{
			cout << "You did not complete the month in running" << endl;
		}

		else
		{
			for (int i = user[confirm].all_running.size() - 1; i > user[confirm].all_running.size() - 366; i--)
			{
				my_running += user[confirm].all_running[i];
			}
			cout << "You run : " << my_running << endl;
		}

		if (user[confirm].all_bicycling.size() < 365)
		{
			cout << "You did not complete the month in bicycling" << endl;
		}

		else
		{
			for (int i = user[confirm].all_bicycling.size() - 1; i > user[confirm].all_bicycling.size() - 366; i--)
			{
				my_b += user[confirm].all_bicycling[i];
			}
			cout << "You bicycled : " << my_b << endl;
		}
		if (user[confirm].all_push_up.size() < 365)
			cout << "You did not complete the month in push_up exercises" << endl;

		else
		{
			for (int i = user[confirm].all_push_up.size() - 1; i > user[confirm].all_push_up.size() - 366; i--)
			{
				my_push += user[confirm].all_push_up[i];
			}
			cout << "you did push ups : " << my_push << endl;

		}
		
		my_sport();
	}

	if (my_choice == 5)
	{
		login_page();

	}
}

void data_project::change_my_information()
{	
	int change_choice = -1;
	string new_name = "";
	string new_password = "";
	int new_high;
	int new_weight;
	int new_aim_weight;

	cout << "What do you want to change" << endl;
	cout << "1) Your name " << endl;
	cout << "2) Your password " << endl;
	cout << "3) your high " << endl;
	cout << "4) Your weight " << endl;
	cout << "5) Your aim weight " << endl;
	cout << "6) back" << endl;
	cin >> change_choice;
	cout << endl;
	while (change_choice < 1 || change_choice >6)
	{
		cout << "sorry choice in range from 1 to 6" << endl;
		cout << "your choice is: ";
		cin >> change_choice;
	}

	if (change_choice == 1)
	{
		cout << "write your new name" << endl;
		cin >> new_name;
		all_names[confirm] = new_name;
		login_name = new_name;
		change_my_information();
	}

	if (change_choice == 2)
	{
		cout << "write your new password " << endl;
		cin >> new_password;
		all_passowrd[confirm] = new_password;
		change_my_information();
	}

	if (change_choice == 3)
	{
		cout << "write your new high" << endl;
		cin >> new_high;
		all_high[confirm] = new_high;
		change_my_information();
	}

	if (change_choice == 4)
	{
		cout << "write your new weight" << endl;
		cin >> new_weight;
		all_wieght[confirm] = new_weight;
		change_my_information();
	}

	if (change_choice == 5)
	{
		cout << "write your new aim weight" << endl;
		cin >> new_aim_weight;
		all_aim_wieght[confirm] = new_aim_weight;
		change_my_information();
	}

	if (change_choice == 6)
		login_page();
	
}

void data_project::rating()
{
	
	if (!check)
	{
		cout << "Please, rate the application from five" << endl;
		cin >> rate;
		while (rate < 1 || rate >5)
		{
			cout << "sorry choice in range from 1 to 5" << endl;
			cout << "your choice is: ";
			cin >> rate;
		}

		cout << "thank you" << endl;
		cout << endl;
		check = true;

	}
	if (check)
	{
		cout << "thank you for rating the application" << endl;
		cout << "your rating is " << rate << endl;
	}

	login_page();
}

bool data_project::is_correct_name_login(string s)
{
	for (int i = 0; i < (int)all_names.size(); i++)
	{
		if (s == all_names[i])
		{
			confirm = i;
			return true;

		}
	}

	return false;
}

bool data_project::is_correct_password_login(string s)
{
	if (all_passowrd[confirm] == s)
	{
		return true;

	}

	return false;
}
int main()
{
	user.main_page();	
}
