# CSC3221-Collision-Detection
A 2D collision detection system and preset 'game' simulation in C++ for CSC3221 coursework component.

Feedback:

---Shape Class---

- Class is pure abstract; appropriate collision detection method was declared virtual
- Auxiliary function for debug printing is correct; desired solution was to override << as: 
    inline std::ostream& operator<<(std::ostream& os, const Shape& s) { return s.print(os); } 
- Appropriate member functions and variables are const correct
- Shape class is efficient due to the choice of member variables

---Circle Class---

- Correct and efficient due to the forward declaration of Square class

---Square Class---

- Correct and efficient due to the forward declaration of Circle class
- Copy constructor and assignment  definitions are correct

---Collision Detection---

- A correct manner of treating collision functionality through the use of smart pointers and dynamic_cast
- Please do not use expensive call to pow(...,2) if it can be replaced with multiplication
- Good use of error checking

---Game Class and General Remarks---

- should use #include<memory> (I'm guessing the coursework was built/deployed from mac). No marks lost here
- Shapes were adequately created and stored. The removal is straight-forward due to the use of smart pointers
- Shape removal after a collision was detected is correctly implemented
- good use of rand()
- error handling was considered
- dynamic cast was used
- rtti and double dispatch were not considered
- Output functionality was implemented but not through the overloading of <<
- Overall, this is an excellent project that finally shows the use of modern C++ functionality

Total: 27.5/30
