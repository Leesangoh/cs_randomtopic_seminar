#include <iostream>
#include <iomanip>
#include <cassert>
using namespace std;
const int CAPACITY = 31;
struct RecordType
{
       int key;
       double otherData;
       int importantData;
};
// Table class member functions
// CONSTRUCTOR function
//    Table( );
// Postcondition: The table is initialized as an empty table.
// MODIFICATION MEMBER FUNCTIONS
// Insert function
//    void insert( const RecordType& entry );
// Preconditions: entry.key >= 0. Also, if entry needs to be added to the table,
//    then there must be room left in the table (size( ) < TABLE_SIZE).
// Postcondition: If the table already has a record with key equal to
//    the key in entry, that record will be replaced by entry.
//    Otherwise, entry will be added as a new record.
// CONSTANT MEMBER FUNCTIONS
// Find function
//     void find( int key, bool& found, RecordType& result ) const;
// Postcondition: If a record with the indicated key is in the table,
//    then found is true and result is set to a copy of that record.
//    Otherwise, found is false and result contains garbage.
// Size function
//    int size( ) const;
// Postcondition: The return value is the number if records in the table.
class Table
{
public:
   Table( );
   void insert( const RecordType& entry );
   void find( int key, bool& found, RecordType& result ) const;
   int size( ) const;
private:
   int hash( int key ) const;
   void findIndex( int key, bool& found, int& i ) const;
   RecordType data[CAPACITY];
   int used;
};
Table::Table( )
{
   used = 0;
   for ( int i = 0; i < CAPACITY; i++ )
      data[i].key = -1;
}
void Table::insert( const RecordType& entry )
{
  // Fill HERE
}
int Table::hash( int key ) const
{
   return key % CAPACITY;
}
int Table::size( ) const
{
   return used;
} 
void Table::findIndex( int key, bool& found, int& i ) const
{
  // FILL HERE
}
void Table::find( int key, bool& found, RecordType& result ) const
{
   int index;
   assert( key >0 );
   findIndex( key, found, index );
   if ( found )
      result = data[index];
}
void print_menu( );
int main( )
{
    //List test;     // A List to perform tests on
    char choice;   // Command entered by the user
    Table dataTable;
    RecordType rec;
    int key;
    bool found;
    int size;
    do
    {
        print_menu( );
        cout << "Enter choice: ";
        cin >> choice;
        cout << endl;
        choice = toupper(choice);
        switch (choice)
        {
            case 'I': // insert
                      cout << "Enter key (int >= 0) for record: ";
                      cin >> rec.key;
                      cout << "Enter other data (double) for record: ";
                      cin >> rec.otherData;
                      cout << "Enter important data (int) for record: ";
                      cin >> rec.importantData;
                      dataTable.insert( rec );
                      cout << "Record was inserted in table" << endl << endl;
                      break;
            case 'F': // find
                      cout << "Enter key (int >= 0) to search for: ";
                      cin >> key;
                      dataTable.find( key, found, rec );
                      if ( found )
                      {
                         cout << "Record was found." << endl;
                         cout << "   key            = " << setw(8)
                              << rec.key << endl;
                         cout << "   other data     = " << setw(8)
                              << rec.otherData << endl;
                         cout << "   important data = " << setw(8)
                              << rec.importantData << endl << endl;
                      }
                      else
                         cout << "Record with key " << key << " not found."
                              << endl << endl;
                      break;
            case 'S': // size
                      size = dataTable.size( );
                      cout << "There are " << size << " records in the table."
                           << endl;
                      cout << "There are " << (CAPACITY - size)
                           << " empty slots left in the table." << endl << endl;
                      break;
            case 'Q': cout << "Test program ended." << endl;
                      break;
            default:  cout << choice << " is invalid." << endl;
        }
    }
    while ((choice != 'Q'));
    return EXIT_SUCCESS;
}
void print_menu( )
{
    cout << endl;
    cout << "The following choices are available: " << endl;
    cout << " I   Insert a new record or update existing record" << endl;
    cout << " F   Find a record" << endl;
    cout << " S   Get the number of records" << endl;
    cout << " Q   Quit this test program" << endl << endl;
}


