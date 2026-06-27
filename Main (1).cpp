#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <string>
using namespace std;

// Global variables
string title = "Shop & Inventory system v2.0";
string dot = "...";
string loadingtext = "Loading";
int refresh = 0;
string exitext = "Exiting";
int choice2;
string returnp = "Would you like to return to main menu?\n1. Return\n2. Exit\nOption: ";

// functions
 // title line 
 void titleline() 
 {for (int p = 0; p < 55; p++)
  {cout << "─" << flush; 
   this_thread::sleep_for(chrono::milliseconds(15));}}

 // loading full
 void loading()
 {for (int l = 0; l < loadingtext.length(); l++)
  {cout << loadingtext[l] << flush;
   this_thread::sleep_for(chrono::milliseconds(50));}
  for (int o = 0; o < 3; o++)
  {cout << dot[o] << flush;
   this_thread::sleep_for(chrono::milliseconds(90));}}

 // title
 void titlename() 
 {for (int j = 0; j < title.length(); j++)
  cout << title[j] << flush;
  this_thread::sleep_for(chrono::milliseconds(25));}

 void exiting()
 {for (int o = 0; o < exitext.length(); o++)
  cout << exitext[o] << flush;
  this_thread::sleep_for(chrono::milliseconds(50));
  for (int l = 0; l < dot.length(); l++)
  {cout << dot[l] << flush;
  this_thread::sleep_for(chrono::milliseconds(60));}
  system("clear");}

 void returntomainmenu()
 {for (int p = 0; p < returnp.length(); p++)
  cout << returnp[p] << flush;
  this_thread::sleep_for(chrono::milliseconds(25));
  cin >>  choice2;
  if (choice2 > 2||choice2 < 1)
  {cout << "\nInvalid option. "; loading();
   this_thread::sleep_for(chrono::milliseconds(400));
   system("clear"); refresh = 0;}
  else if (choice2 == 1)
  {loading(); system("clear"); refresh = 0;}
  else if (choice2 == 2) {exiting();}}

int main() {
// variables
string choices = "1. Shop\n2. Inventory\n3. Balance\n4. Exit\nOption: ";
int option;
double balance = 0;
struct ore {string name; int value;};
ore ore1 = {"Diamond", 500};
ore ore2 = {"Gold", 300};
ore ore3 = {"Silver", 250};
int choosebuy;
int buyorleave;
struct playerinv {string ore; int quantity;};
vector<playerinv> inv;

// main menu
while (refresh == 0)
{refresh ++; 
titleline(); cout << "\n             ";
titlename(); cout << "\n";
titleline(); cout << "\n\n";
for (int i = 0; i < choices.length(); i++)
{cout << choices[i] << flush;
 this_thread::sleep_for(chrono::milliseconds(30));}
cin >> option;

// exit
if (option == 4)
{this_thread::sleep_for(chrono::milliseconds(500)); exiting();}

// invalid
else if (option > 4||option < 1)
{cout << "\nInvalid option. "; loading();
 this_thread::sleep_for(chrono::milliseconds(400));
 system("clear"); refresh = 0;}

// balance
else if (option == 3)
{cout << "\n"; loading();
 this_thread::sleep_for(chrono::milliseconds(30));
 cout << "\nYour current balance is $" << balance
 << "\n"; returntomainmenu();}

// shop
else if (option == 1)
{cout << "\n1. " << ore1.name << " Legendary $" << ore1.value
 << "\n2. " << ore2.name << " Epic $" << ore2.value << "\n3. "
 << ore3.name << "Epic $" << ore3.value << "\n1.Buy\n2.Leave\nOption: ";
 cin >> buyorleave;
 // buy
 if (buyorleave == 1)
 {cout << "Buy ore #"; cin >> choosebuy;
  // diamond
  if (choosebuy == 1)
  {bool search = false;
   for (int s = 0; s < inv.size(); s++)
   {if (inv[s].ore == ore1.name)
    {inv[s].quantity++; search = true; break;}}
    if (!search)
    {playerinv tempinv;
    tempinv.ore = ore1.name; tempinv.quantity = 1;
    inv.push_back(tempinv);}}
  // Gold
  else if (choosebuy == 2)
  {bool search = false;
   for (int s = 0; s < inv.size(); s++)
   {if (inv[s].ore == ore2.name)
    {inv[s].quantity++; search = true; break;}}
    if (!search)
    {playerinv tempinv;
    tempinv.ore = ore2.name; tempinv.quantity = 1;
    inv.push_back(tempinv);}}
  // Silver
  else if (choosebuy == 3)
  {bool search = false;
   for (int s = 0; s < inv.size(); s++)
   {if (inv[s].ore == ore3.name)
    {inv[s].quantity++; search = true; break;}}
    if (!search)
    {playerinv tempinv;
    tempinv.ore = ore3.name; tempinv.quantity = 1;
    inv.push_back(tempinv);}}
   // exit
   else if (option == 4)
   {cout << "\n"; loading();
   system("clear"); refresh = 0;}}
  returntomainmenu();}
    
 // Inventory
 else if (option == 2)
 {cout << "\nYour Inventory:\n";
  for (int i = 0; i < inv.size(); i++)
  {cout << inv[i].ore << " x" << inv[i].quantity 
  << "\n" << flush; 
  this_thread::sleep_for(chrono::milliseconds(30));}
  returntomainmenu();}
 }
}
