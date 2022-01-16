// incomplete
#include<iostream>
#include<vector>
using namespace std;

class Book{
    string title;
    string authorName;
    int accessNo;
    float price;
    
    public:
    friend istream& operator>>(istream&,Book&);
    friend ostream& operator<<(ostream&,Book&);
    bool operator<(Book&);
    bool operator>(Book&);
    void operator=(Book&);
};
istream& operator>>(istream& in, Book& b)
{
	in >> b.title >> b.authorName >> b.accessNo >> b.price;
}
ostream& operator<<(ostream& out, Book& b)
{
	out << b.title << "\n" << b.authorName<< "\n" << b.accessNo<< "\n" << b.price;
}
bool Book::operator<(Book& b)
{
    return(accessNo<b.accessNo);
}
bool Book::operator>(Book& b)
{
    return(accessNo>b.accessNo);
}
void Book::operator=(Book& b)
{
    title = b.title;
    authorName = b.authorName;
    accessNo= b.accessNo;
    price= b.price;
}
int main()
{
    Book elements[20];
    Book key;
    int i, j, n;
    //cout<<"Enter number of elements";
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> elements[i];
    
    for(j = 1; j < n; j++)
    {
        key = elements[j];
        i = j - 1;
        while((i >= 0) && (elements[i] > key))
        {
            elements[i+1] = elements[i];
            i = i - 1;
        }
        elements[i+1] = key;
    }
   for(i = 0; i < n; i++)
    {
        cout << elements[i] << "\n";
    }
}