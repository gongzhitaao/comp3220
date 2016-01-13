// point-struct.cpp

#include <iostream>
#include <string>

// For convenient, we include everything from std.  Normally if you
// are writing a library, DO NOT do this.
using namespace std;

struct Student {
  string tiger_id;
  int age;
  string first_name;
  string last_name;
};                              // REMEMBER THIS REMICOLON!!!

void print_student_info(const Student& s, ostream& os = cout)
{
  os << "tiger_id: " <<  s.tiger_id << endl
     << "age: " << s.age << endl
     << "first_name: " << s.first_name << endl
     << "last_name: " << s.last_name << endl;
}

// One way for a function to return multiple values
Student gen_null_student()
{
  return {"0", "0", "f", "l"};
}

int main()
{
  // Full initialized
  Student s0 {"1", 20, "f0", "l0"};
  print_student_info(s0);

  // Default value
  Student s1 {"2"};
  print_student_info(s1);

  // Dot notation to access fields.
  s0.tiger_id = "3";
  s1.age = 100;

  // -----------------------------------------------------------------

  // Pointer to struct
  Student* s2 = new Student {"3", 40, "f2"};

  // For pointers we use -> to access fields.
  s2->tiger_id = "100";
  s2->age = -3;

  print_student_info(*s2);
  delete s2;                    // Remember to return space

  // -----------------------------------------------------------------

  // size of Student?  Extra space?  For performance reasons, the
  // compiler will sometimes add gaps into structures, i.e.  padding.
  cout << sizeof(Student) << endl;
  cout << sizeof(s0) << endl;
  cout << sizeof(string) << endl;
}
