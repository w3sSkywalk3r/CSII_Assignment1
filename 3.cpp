//
//   COPYRIGHT (C) wec16@uakron.edu>, 2022  All rights reserved.
//   Wesley Cunningham
//   To better understand Classes in C++
//
#include <cassert>
#include <iosfwd>
#include <iostream>
#include <iomanip>
#include <memory>
#include <cstring>

//Global constants

// *************************************************
// PLACE ALL OF THIS PROGRAM'S prototypes and Declarations here
//
// This code would normally go into a dot hpp file
//
// SPECIFICATION HERE
//
// *************************************************

class myType
{
  public:
    myType(); // Default construction; the default value shall be the empty object.

    myType(const char *);
    //Pre: pointer must not be a null pointer
    //Post: will initialize an object to a object literal

    myType(const char *, std::size_t);
    //Pre: c-object must not be null and have valid size as size_t
    //Post: will initialize object to the amount of characters in a literal
    myType(const myType&);
    //All operator overloads
    myType& operator=(const myType&);
    myType& operator+=(const myType&);
    bool operator==(const myType&) const;
    char& operator[](unsigned int);
    char operator[](unsigned int) const;
    bool operator!=(const myType&) const;
    bool operator<(const myType&) const;
    bool operator>(const myType&) const;
    bool operator<=(const myType&) const;
    bool operator>=(const myType&) const;
    operator short int();



    // code the remainder of the method prototypes ...
    //Class functions
     bool empty() const;

     size_t size() const;

     char* data() const;

     void clear();

     size_t find(char) const;

     myType subpart(size_t, size_t) const;



    ~myType() //deconstructor
    {

        delete [] typeVar;

        typeVar = nullptr;

    }

    // Defines the npos value. for the myType class
    static constexpr std::size_t npos = -1;

  private:
    char *typeVar;
	  std::size_t typeLength;
};

int
main()
{

  // these are declarations - prefer this or std:: prefix
  using std::setw;
  using std::left;
  using std::right;
  short points = 0;
  char myChrs[] = {'1', '8', '4', ' ', 'd', 'i', 'v', ' ', '6', '\0'};
  // Check the default contstructor (ctor).

  {
    myType t0;
    assert(t0.empty());
    std::cout << "default ctor and empty passed " << std::endl;
    points += 2;
  }


  // A member function to return the length of the object.
  // Returns a std::size_t (unsigned integer) value. The size() function
  // shall not modify the object t1.
  //
  // This operation shall be constant time (i.e., you cannot traverse the
  // underlying object to compute the length).

  {
    myType t1 = "365 div 7";
    std::size_t n = t1.size();
    std::cout << "Size is " << n << std::endl;
    points += 2;
  }



  // object ctor
  {
    char const *str = "402 add 5009";
    myType t2 = str;
    assert(t2.data() != str);
    assert(strcmp(t2.data(), str) == 0);
    std::cout << "object ctor passed " << std::endl;
    points += 2;
  }

  // Raw C-object access, which returns the underlying array of
  // characters as a pointer. This member function shall not modify its
  // object.
  {
    myType t3 = "5764 div 9";
    char const *p1 = t3.data();
    std::cout << "object raw ptr access passed " << std::endl;
    points += 2;
  }

  // Copy ctor
  // Initialization by a c-string array. The initialized object (t1)
  // shall be equal to the char array after initialization.
  {
    myType t1 = myChrs;
    assert(!strcmp(t1.data(), myChrs));
    std::cout << "copy ctor passed " << std::endl;
    points += 2;
  }

  // copy ctor plus
  // Initialization by a literal. The initialized object (t4)
  // shall be equal to the literal after initialization.
  // The literal shall not be a null pointer. You must assert
  // this property.
  // Copy construction. The initialized object (t5) shall be equal to
  // the original (t4) after initialization.
  {
    myType t4 = "900 mlt 9";
    myType t5(t4);
    assert(strcmp(t4.data(), t5.data()) == 0);
    std::cout << "copy ctor plus passed " << std::endl;
    points += 2;

  }
  // Initialization by a bounded literal. The initialized object (t2)
  // shall be equal to the first n characters of the given literal.
  // The object shall not be null and shall have at least length n.
  // You must assert this property. Hint: use std::strnlen and be aware
  // that it may not insert a null-terminator.

  {
    myType t2("76 sub 75", 6); // t2 is equal to "76 sub".
    assert(!strcmp(t2.data(), "76 sub"));
    std::cout << "portion ctor passed " << std::endl;
    points += 2;
  }

  // Copy assignment. After assignment, the assigned object on the left (t1)
  // shall be equal to the value on the right (t2).

  {
    myType t1 = "99 sub 0";
    myType t2;
    t2 = t1;
    assert(strcmp(t1.data(), t2.data()) == 0);
    std::cout << "copy assignment passed " << std::endl;
    points += 2;
  }

{

    // Compound @@ addition/assignment (concatenation). Compounds (adds)
    // the left and right values to form the updated t4 @@.
    myType t4("727 mlt 3");
    myType t5("3 mlt 3");
    std::cout << t4.data() << std::endl;
    t4 += t5;
    std::cout << t4.data() << std::endl;
    std::cout << "compound assignment passed " << std::endl;
    points += 2;
  }

  // Assignment to an object. After assignment, the object on the left (t1)
  // shall be equal to the object literal on the right.
  {
    myType t1;
    t1 = "32767 sub -32768";
    assert(!strcmp(t1.data(), "32767 sub -32768"));
    std::cout << "object literal assignment passed " << std::endl;
    points += 2;
  }

  // Assignment to an object. After assignment, the object on the left (t1)
  // shall be equal to the c-string on the right.
  {
    myType t1;
    t1 = myChrs;
    assert(!strcmp(t1.data(), myChrs));
    std::cout << "object cstring assignment passed " << std::endl;
    points += 2;
  }

  // self assign
  {
    myType t1 = "-32767 sub 32767";
    t1 = t1;
    std::cout << "object literal assignment passed " << std::endl;
    points += 2;
  }

  // A member function to determine make an object is empty.
  // the object is cleared of any and all values (emptied)
  {
    myType t1 = "-32767 sub 32767";
    t1.clear();
    assert(t1.empty());
    std::cout << "clear passed " << std::endl;
    points += 2;
  }

  // A member function to determine if a object is empty. Returns true
  // if t1 is the empty object. The empty() function shall not modify
  // the object t1 (i.e., the member function must be const).
  {
    myType const t1;
    assert(t1.empty());
    myType const t2 = "";
    assert(t2.empty());
    std::cout << "empty passed " << std::endl;
    points += 2;
  }

  // Character access. Support reading and writing of characters using
  // the subscript operator. Both operators take a std::size_t argument n,
  // such that n >= 0 and n < size(). You must assert that the index is
  // in bounds.
  {
    myType t1 = "767 sub 768";
    t1[0] = '7';
    assert(t1[0] == '7');

    myType const t2 = "95 div 5";
  //  std::cout << decltype(t1[0]);
    assert(t2[0] != 't');
    std::cout << "index accessing passed " << std::endl;
    points += 2;
  }

  // A member function that returns the index of the first character
  // in the object. This shall return a std::size_t value. If no such
  // character exists, return npos. Hint: see std::strchr.
  //
  // Note that npos is already defined within your class.
  //
  // This function shall not modify its object.
  {
    myType const t1 = "85 sub 40";
    assert(t1.find('s') == 3);
    assert(t1.find('x') == t1.npos);
    std::cout << "find passed " << std::endl;
    points += 2;
  }

  // A member function that creates a subpart comprising all of the
  // characters starting at an index i and containing n characters. The
  // index i shall be a valid position in the object. You must assert
  // this condition. If n is larger than the number of characters past i
  // then all characters after i are copied to the the output.
  // Hint: use your bounded C-object constructor.
  //
  // This function shall not modify its object.

  {
     // std::cout << "Before subpart." << std::endl;
    myType const t1 = "700 mlt 7";
    myType t2 = t1.subpart(0, 3);
    //std::cout << "After t1 subpart." << std::endl;
    //std::cout << t1.subpart(0,3) << std::endl;
   myType t3 = t1.subpart(4, 3);


    assert (t2 == "700");
    assert (t3 == "mlt");
    std::cout << "object subpart passed " << std::endl;
    points += 2;
  }

  // Equality comparisons. Two objects compare equal when they have the
  // same sequence of characters. Hint: see std::strcmp.
  {
    myType const t1 = "855 sub 854";
    myType const t2 = "7 add 7";
    assert(t1 == t1);
    assert(t1 != t2);
    std::cout << "object equality comparison passed " << std::endl;
    points += 2;
  }

  // ordering. One object compares less than another when it lexicographically
  // precedes it. Hint: see std::strcmp
  {
    myType t1 = "855 sub 854";
    myType t2 = "854 sub 855";
    assert(t1 < t2);
    assert(t2 > t1);
    assert(t1 <= t1);
    assert(t1 >= t1);
    std::cout << "lexicographic ordering passed " << std::endl;
    points += 2;
  }

  // self concatenation
  {
    myType t1 = "843 add 7";
    t1 += t1;
    myType t2 = "843 add 7";
    assert(t1 == t2);
    std::cout << "self-concatenation avoided " << std::endl;
    points += 2;
  }

  // computational conversion @@ - convert the cstring into an expression and
  // return the result as a short integer

  {
    myType t1 = "843 add 7";
    short answer1 = t1;
    std::cout << "Addition = " << answer1 << std::endl;
    myType t2 = "857 sub 7";
    short answer2 = t2;
    std::cout << "Addition = " << answer2 << std::endl;
    assert(answer1 == answer2); // should be true
    std::cout << "computational conversions passed" << std::endl;
    points += 6;
  }

  std::cout << "Total points based on results: " << points << std::endl;
  std::cout << "end of myType testing" << std::endl;
  std::cin.get();
}


// This code hereafter would normally go into a dot cpp file

std::ostream& operator<<(std::ostream& input, myType const& rhs)
{
    input << rhs.data();
    return input;
}

// PLACE CODE HERE




//Default Constructor
myType::myType()
{

      typeVar = NULL;
      typeLength = 0;

}

//Constructor that has a char array passed as a parameter
myType::myType(const char *typeArr)
{

    typeVar = new char[strlen(typeArr) + 1];
    strcpy(typeVar, typeArr);
    typeLength = strlen(typeVar);
    typeVar[typeLength] = '\0';
}

//Constructor that is passed an array, and size as a parameter
myType::myType(const char *typeArr, std::size_t lengthType)
{
     typeVar = new char[lengthType + 1];
    strncpy(typeVar, typeArr, lengthType);
    typeLength = lengthType;
    typeVar[typeLength] = '\0';

}

//Empty function, returns true or false, depending if there is a type length function or not
bool myType::empty() const
{
   if(typeLength == 0)
   {
       return true;
   }
   else
   {
       return false;
   }
}

//Returns the current myType object's typeLength
size_t myType::size() const
{
   return typeLength;
}

//Returns the current myType object's typeVar
char* myType::data() const
{

    return typeVar;

}

//Clears the current objects typeLength and typeVar
void myType::clear()
{
    typeLength = 0;
    typeVar = NULL;
}

//Finds the char that is passed in the parameter
size_t myType::find(char letterFind) const
{
    char* indexLetter;

   if(strchr(typeVar, letterFind) == NULL)
   {
       return npos;
   }
   else
   {
       indexLetter = strchr(typeVar, letterFind);
       int letterPosition = indexLetter - typeVar;
   }
}

//Creates a substring beginning at the first parameter passed, and as long as the second parameter passed
myType myType::subpart(size_t index, size_t numChars) const
{
    myType tempArr(&typeVar[index], numChars );
    return tempArr;
}

//Copy Constructor
myType::myType(const myType& rhs)
{
    typeLength = rhs.size();
    typeVar = new char[typeLength + 1];
    strcpy(typeVar, rhs.data());
    typeLength = strlen(typeVar);
    typeVar[typeLength] = '\0';

}

//Assignment operator overload so a predefined myType object can be assigned
myType& myType::operator=(const myType& rhs)
{
    if(typeVar == NULL)
    {
      typeLength = rhs.size();
    typeVar = new char[typeLength + 1];
    for(auto i=0; i < rhs.size() + 1; ++i)
    {
        typeVar[i] = rhs.typeVar[i];
    }
    }
    else
    {

    delete[] typeVar;
    typeLength = rhs.size();
    typeVar = new char[typeLength + 1];
    for(auto i=0; i < rhs.size() + 1; ++i)
    {
        typeVar[i] = rhs.typeVar[i];
    }
    }
}

//+= operator adds the first operand and second operand
//if it is passing the same value then it does not concatenate
myType& myType::operator+=(const myType& rhs)
{
    if(typeVar == rhs.typeVar)
    {
        typeVar = typeVar;
    }
    else
    {

    char lhsArr[4];
    char rhsArr[4];
    int lhsOp1;
    int lhsOp2;
    int rhsOp1;
    int rhsOp2;
    int resultOp1;
    int resultOp2;

    std::stringstream lhsStream;
    std::stringstream rhsStream;
    std::stringstream resultStream;


    lhsStream << typeVar;
    rhsStream << rhs.typeVar;

    lhsStream >> lhsOp1 >> lhsArr >> lhsOp2;
    rhsStream >> rhsOp1 >> rhsArr >> rhsOp2;

    resultOp1 = rhsOp1 + lhsOp1;
    resultOp2 = rhsOp2 + lhsOp2;
    resultStream << resultOp1 << " " << lhsArr << " " << resultOp2;

    strncpy(typeVar, resultStream.str().c_str(), resultStream.str().size());
   //I know the assignment said not to use strings but after discussing the use of stringstream
   //I did not see another way to convert the stringstream to a cstring.
    typeLength = strlen(typeVar);
    }

}

//returns true if each object's typeVar is equivalent
//returns false if the object's typeVar is not equivalent
bool myType::operator==(const myType& rhs) const
{
    if(strcmp(typeVar, rhs.data()) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }


}

//returns true if each object's typeVar is not equivalent
//returns false if each object's typeVar is equivalent
bool myType::operator!=(const myType& rhs) const
{
    if(strcmp(typeVar, rhs.data()) == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

//Allows myType to use the subscript operator
char& myType::operator[](unsigned int index)
{
    return typeVar[index];
}

//Allows myType to have an integer in the subscript operator
char myType::operator[](unsigned int index) const
{
    return typeVar[index];
}

//Tests if left hand side's typeVar is less than the right hand's typeVar
bool myType::operator<(const myType& rhs) const
{
    if(strcmp(typeVar, rhs.typeVar) > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Tests if left hand side's typeVar is greater than the right hand's typeVar
bool myType::operator>(const myType& rhs) const
{
    if(strcmp(typeVar, rhs.typeVar) < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Tests if left hand side's TypeVar is less than or equal to right hand's side typeVar
bool myType::operator<=(const myType& rhs) const
{
    if(strcmp(typeVar, rhs.typeVar) <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Tests if right hand side's typeVar is greater than or equal to right hand's side typeVar
bool myType::operator>=(const myType& rhs) const
{
    if(strcmp(typeVar, rhs.typeVar) >= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


//Converts myType to short int to use as a mathematical operation using stringstream
 myType::operator short int()
{
    std::stringstream operationStream;
    short Op1;
    short Op2;
    short resultOp;
    char operandArr[4];
    operationStream << typeVar;


    operationStream >> Op1 >> operandArr >> Op2;
    std::cout << Op1 << std::endl;
    std::cout << Op2 << std::endl;
    std::cout << operandArr << std::endl;

    if(operandArr[0] == 'm')
    {
        resultOp = Op1 * Op2;
        return resultOp;

    }
    else if(operandArr[0] == 'a')
    {
        resultOp = Op1 + Op2;
        return resultOp;

    }
    else if(operandArr[0] == 's')
    {
        resultOp = Op1 - Op2;
        return resultOp;

    }
    else
    {
        resultOp = Op1 / Op2;
        return resultOp;

    }

}


