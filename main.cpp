#include <iostream>
#include <string>
using namespace std; 

string text;
string key;

void textykey()   
{
  string txt;
  cout << "Enter your preferred text: ";  //Asks for user's text
  getline(cin, txt);   //getline to get text
  cin.ignore();
  
  for(int i=0; i<text.length(); i++)
  { 
    text[i] = toupper(text[i]);
  }

  string Ckey;  //Cipher key 
  cout << "Enter the key: ";  //Asks for key
  getline(cin, Ckey);   //getline to get key 
  cin.ignore();

  for(int i=0; i<Ckey.length(); i++)
  {
    Ckey[i] = toupper(Ckey[i]);
  }

  string Tkey = ""; //Setting key to text
  for (int i = 0, j = 0; i<txt.length(); i++)
  {
    if(txt[i] == 32)
    {
      Tkey += 32;
    }
    else
    {
      if(j<Ckey.length())
      {
        Tkey += Ckey[j];
        j++;
      }
      else 
      {
        j = 0;
        Tkey += Ckey[j];
        j++;
      }
    }  //End of if statement 
  }   //End for loop 
text = txt;
key = Tkey;
}   //End of void

int itrCt(int Ckey, int text)   //ASCII(represents text in computers)
{
  string result = "";
  int counter = 0;

  for(int i=0; i <26; i++) //26 letters in alphabet 
  {
    if(Ckey+i > 90)
    {
      result += (char)(Ckey+(i-26));
    }
    else 
    {
      result += (char)(Ckey+i);
    }
  }  

  for(int i=0; i<result.length(); i++)
  {
    if(result[i] == text)
    {
      break;
    }
    else
    {
      counter++;
    }
  }

  return counter;
}

void cipDecrypt(string text, string key)  //decrypt
{
  string deText = "";
  
  for(int i = 0; i <text.length(); i++)
  {
    if(text[i]==32 && key[i]==32)
    {
      deText += " ";
    }
    else 
    {
      int temp = itrCt((int)key[i], ((int)text[i]));
      deText += (char)(65+temp);
    }
  }

  cout << "Your Decrypted Text is: " << deText;
}

int Array[26][26];    //table
void createvig()
{
  for(int i = 0; i < 26; i++)
  {
    for(int j = 0; j < 26; j++)
    {
      int temp;
      if((i+65) + j > 90)
      {
        temp = ((i+65)+j)-26;

        Array[i][j] = temp;
      }
    }
  }
}

void cipEncrypt(string text, string key)    //Encrypt  
{
string enText = "";
createvig();
for(int i=0; i < text.length(); i++)
{
  if(text[i] == 32 && key[i] == 32)
  {
    enText += " ";
  }
  else
  {
    int x = (int)text[i]-65;
    int y = (int)text[i]-65;
    enText += (char)Array[x][y];
  }
}

cout << "Your Encrypted Text is: " << enText; 
}

void Menu() //Menu
{
      cout << "\nWelcome to Vigenere Cipher!" << endl; //Welcome Message/Rules messages! 
    cout << "\nIn this program you can either Decrypt or Encrypt a text of your choice!" << endl;
    cout << "\nTo begin all texts and keys must be uppercase letters(A-Z) with no symbols or numbers." << endl;

    cout << "\nNow please choose from the following choices:\n" << endl;
    cout << "1: Decryption\n";
    cout << "2: Encryption\n";
    cout << "3: Exit\n";
}

void ciprun() 
{
int choice;      //an integer since it will be only 1 or 2 they can pick from. 
    cin >> choice;  //User makes choice. 1 = Decryption, 2 = Encryption 
    cin.ignore();   //Ignores the amount of characters when called. 
    
    
    if (choice == 1) //Choice 1 = Decryption
      {
        cout << "You have chosen Decryption." << endl; 
        textykey();
        cipDecrypt(text, key);
      }
      else if (choice == 2) // Choice 2 = Encryption
      {    
        cout << "You have chosen Encryption." << endl; 
        textykey();
        cipEncrypt(text, key);
      }
      else if (choice == 3)
      {
        cout << "Goodbye.";
      }
      else  //Choice if user picks any number other than 1-2. 
      {
        cout << "Not possible, you can only pick from choices 1-3!" << endl; 
      }
  
}

int main() 
{
    Menu();
    ciprun();
    
    cout << "\nThanks for using the Vigenere Cipher!\n";
    cout << "\nIf you would like to try again, please restart the program!\n";

  return 0; 
}