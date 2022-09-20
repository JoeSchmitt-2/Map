//By: joseph schmitt
mapp.cpp                                                                                                                                                                                               ustar   jschmitt                        CS-Grads                                                                                                                                                                                                               #include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

bool cmpString(pair<string, int> a,
         pair<string, int> b)
{
    return a.second > b.second;
}

void sortWords(map<string, int> M)
{
    vector<pair<string, int> > A;
    int count = 0;

    for (auto& it : M)
    {
        A.push_back(it);
    }
    sort(A.begin(), A.end(), cmpString);

    //
    //THIS DELETES THE WHITESPACE RECORDED
    //
    A.erase(A.begin(), A.begin() + 1);

    for (auto& it : A)
    {
        cout << "No. " << count << ": " << it.first << "\t"
             << it.second << endl;
        count++;
        if(count > 9)
            break;
    }
}

void sort(map<string, int> M)
{
    vector<pair<string, int> > A;
    int count = 0;

    for (auto& it : M)
    {
        A.push_back(it);
    }

    sort(A.begin(), A.end(), cmpString);

    for (auto& it : A)
    {
        cout << "No. " << count << ": " << it.first << "\t"
             << it.second << endl;
        count++;
        if(count > 9)
            break;
    }
}

int main()
{
    map<string , int> m;
    map<string, int> words;
    map<string, int> numbers;
    map<char, int>::iterator itr;

    //******change this for final product******
    //****needs to handle input redirection****

    std::string contents;

    for (std::string line; std::getline(std::cin, line); )
    {
    contents += line;
    }

    string str;
    //this loop organizes characters by frequency
    for(long i = 0;i < contents.length(); i++)
    {
        if(contents.at(i) == '\n')
        {
            m["\\n"]++;
        }
        else
            m[str.assign(1, contents.at(i))]++;
    }

    int const MAX_SIZE = 10;
    if(m.size() > MAX_SIZE)
    {
        cout << "Total " << m.size() - 1 << " different characters, " << MAX_SIZE
             << " most used characters:" << endl;
    } else
        cout << "Total " << m.size() - 1 << " different characters, " << m.size() - 1
             << " most used characters:" << endl;

    sort(m);

    //this changes the string to lower case since it is case insensitive
    for_each(contents.begin(), contents.end(), [](char & c) {
        c = ::tolower(c);
    });

    //this loop iterates through the characters and builds words
    string s[10000];
    int word = 0;
    for(int i = 0; i < contents.length(); i++)
    {
        if((i == contents.length()-1) && contents.at(i) > 96 && contents.at(i) < 123)
        {
            s[word] = s[word] + contents.at(i);
            words[s[word]]++;
        }
        else if(contents.at(i) > 96 && contents.at(i) < 123)
            s[word] = s[word] + contents.at(i);
        else
        {
            words[s[word]]++;
            word++;
        }
    }

    if(words.size() > MAX_SIZE)
    {
        cout << "Total " << words.size() - 1 << " different words, " << MAX_SIZE
             << " most used characters:" << endl;
    } else
        cout << "Total " << words.size() - 1 << " different words, " << words.size() - 1
             << " most used words:" << endl;

    sortWords(words);


    string n[1000];
    int num = 0;
    for(int i = 0; i < contents.length(); i++)
    {
        if(contents.at(i) == '0' || contents.at(i) == '1' ||
           contents.at(i) == '2' || contents.at(i) == '3' ||
           contents.at(i) == '4' || contents.at(i) == '5' ||
           contents.at(i) == '6' || contents.at(i) == '7' ||
           contents.at(i) == '8' || contents.at(i) == '9')
        {
            n[num] = n[num] + contents.at(i);

        } else
        {
            numbers[n[num]]++;
            num++;
        }
    }

    if(numbers.size() > MAX_SIZE)
    {
        cout << "Total " << numbers.size() -1 << " different numbers, " << MAX_SIZE
             << " most used numbers:" << endl;
    } else
        cout << "Total " << numbers.size() -1 << " different numbers, " << numbers.size() -1
             << " most used numbers:" << endl;


    sortWords(numbers);

}
