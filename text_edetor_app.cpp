#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <fstream>
using namespace std;


void LoadFile( vector<string>& text, fstream& File , string& filename)
{
//    get file name
//     open file
//      if ! file.fail so load into text
//      else so print message text is empty

//    C:\Users\MSI\OneDrive\Desktop\test.txt

    char line [100];
    cout << "please enter file name :  " << endl;
    getline(cin,filename);
    File.open(filename, ios::in );
    if (!File.fail())
    {
        cout << "File was opened successfully \n" << endl;
        while (!File.eof())
        {
            File.getline(line,100,'\n');
            text.push_back(string(line));
        }
        File.close();
    }
    else
    {
        cout << "This file cannot be found" <<endl;
        File.open(filename, ios::out);

        cout << "A new file will be created when saving  " << endl;
    }


}

int displayMenu()
{
    int choice ;

    cout << "1. Add new text to the end of the file\n"
            "2. Display the content of the file\n"
            "3. Empty the file\n"
            "4. Encrypt the file content\n"
            "5. Decrypt the file content\n"
            "6. Merge another file\n"
            "7. Count the number of words in the file.\n"
            "8. Count the number of characters in the file\n"
            "9. Count the number of lines in the file\n"
            "10. Search for a word in the file\n"
            "11. Count the number of times a word exists in the file\n"
            "12. Turn the file content to upper case.\n"
            "13. Turn the file content to lower case.\n"
            "14. Turn file content to 1st caps (1st char of each word is capital)\n"
            "15. Save\n"
            "16. Exit"<< endl;
    cin >> choice;



    return choice;
}

void AppendText(vector <string>& text , fstream& File , string& filename)
{
    string NewText;
//    read the new text from user
    cout<<"Please enter the new added text : " << endl;

    cin.ignore();
    getline(cin,NewText);


    //    open file in appending mode
    File.open(filename, ios::app);


//   appending new text in file
    File << NewText<< endl ;

//    }

    File.close();

    cout<<"A new text has been added "<< endl;

//    to check content of text
    text.push_back(NewText);
    for (string &line: text)
    {
        cout << line << endl;

    }

}

void DisplayData(vector <string>& text , fstream& File, string& filename)
{

    for (string &line: text)
        cout << line << endl;

}

void EmptyFile(vector <string>& text , fstream& File, string& filename)
{
    File.open(filename, ios::out);
    File.close();

    cout << "DONE! File is empty now " << endl;

    /*
     the second line
the third line
the fourth line
the fifth line
the second line
the third line
the fourth line
the fifth line
lllllllllllllllllllllllllllllll

kkkkkkkkkkkk
ggggggggggggggggggggggggggggggggg
farah awlid ahmed

     */
}

void ConvertToLower(vector <string>& text , fstream& File ,string& filename )          //هديها السطور
{

    File.open(filename, ios::out );


    for (int i =0 ; i < text.size() ; i++ )             //text.size()== no of lines
    {
        for (int j = 0 ; j < text[i].size() ; j++)      //text[i].size() == كل ما السطر i فيه charهات اللى بعده روح
        {
            text[i][j] = tolower(text[i][j]);
        }
        File << text[i] << endl ;

    }


    File.close();



}

void ConvertToUpper(vector <string>& text, fstream& File , string& filename)          //هديها السطور
{
    File.open(filename, ios::out );

    for (int i =0 ; i < text.size() ; i++ )             //text.size()== no of lines
    {
        for (int j = 0 ; j < text[i].size() ; j++)      //text[i].size() == كل ما السطر i فيه charهات اللى بعده روح
        {
            text[i][j] = toupper(text[i][j]);

        }
        File << text[i] << endl ;

    }

    for (string &line: text)
        cout << line << endl;
}

void CountNumWords(vector <string>& text, fstream& File , string& filename)
{

    int NumberWords = 1  ;
    char ch;


    File.open(filename, ios::in );

    while(!File.eof())
    {
        for (int i =0 ; i < text.size() ; i++ )             //text.size()== no of lines
        {
            for (int j = 0 ; j < text[i].size() ; j++)      //text[i].size() == كل ما السطر i فيه charهات اللى بعده روح
            {
                ch = text[i][j];
                if (isalpha((ch)) && isdigit(ch))
                {
                    NumberWords = NumberWords;
                }
                else
                {
                    NumberWords++ ;

                }

            }
        }
    }
    cout << "Number of words is : " << NumberWords << endl;



}

void CountNumberChar(vector <string>& text, fstream& File , string& filename)
{
    char chr ;
    int NumberChar;

    File.open(filename, ios::in );

    while(!File.eof())
    {
        File.get(chr);
        if(chr != '\n')
        {
            NumberChar++ ;
        }
    }

    cout << "Number of characters is : " << NumberChar << endl;

}

int main()
{


    /*
    1) load file
        take path \ name
        existing or not
        into what ?(vector of string \  )
        can read and save
      */

    fstream SourceFile;
    vector<string> text;
    string FileName;
    int choice;


    LoadFile(text, SourceFile , FileName );

//    for (string &line: text)
//        cout << line << endl;


//    2) while (true )
//    {
//        displayMenu()
//        getChoice
//        if choice == 1 {.....}
//        if choice == 2 {.....}


    while (true)
    {
        choice = displayMenu();
        switch (choice)
        {
            case 1 :
                    AppendText(text , SourceFile , FileName);

                    break;
            case 2 :
                    DisplayData(text , SourceFile ,FileName);
                    break;
            case 3 :
                    EmptyFile(text , SourceFile ,FileName);
                    break;
            case 4 :


            case 5 :

                    break;
            case 6 :

                    break;
            case 7 :
                    CountNumWords(text , SourceFile , FileName);
                    break;

            case 8 :
                    CountNumberChar(text , SourceFile , FileName);
                    break;

            case 9 :
                    cout << "Num of lines =" << text.size() << endl;
                    break;

            case 12 :
                    ConvertToUpper(text , SourceFile , FileName);
                    break;

            case 13 :
                    ConvertToLower(text , SourceFile , FileName);
                    break;
            case 16 :
                    return 0;

            default:
                    cout << "INVALID CHOICE , PLease try again." << endl;
                    displayMenu();
        }
//        getChoice
//        if choice == 1 {.....}
//        if choice == 2 {.....}


    }

    SourceFile.close();

}
