class Student {
    constructor(id, firstName, lastName, email, password) {
      this.id = id;
      this.firstName = firstName;
      this.lastName = lastName;
      this.email = email;
      this.password = password;
      this.created_at = new Date();
    }
  }
  
  class Lecture {
    constructor(id, name) {
      this.id = id;
      this.name = name;
      this.created_at = new Date();
    }
  }
  
  class Unit {
    constructor(id, name, lecture_id) {
      this.id = id;
      this.name = name;
      this.lecture_id = lecture_id;
      this.created_at = new Date();
    }
  }
  
  class Grade {
    constructor(id, student_id, unit_id, value) {
      this.id = id;
      this.student_id = student_id;
      this.unit_id = unit_id;
      this.value = value;
      this.created_at = new Date();
    }
  }
  
  // Sample data
  let students = [];
  let lectures = [];
  let units = [];
  let grades = [];
  
  // Function to add a student
  function addStudent(firstName, lastName, email, password) {
    const newStudent = new Student(students.length + 1, firstName, lastName, email, password);
    students.push(newStudent);
  }
  function getGrades(email, password, unitName) {
    const user = students.find((student) => student.email === email && student.password === password);
  
    if (user) {
      const studentGrades = grades.filter((grade) => grade.student_id === user.id);
      const unit = units.find((unit) => unit.name === unitName);
  
      if (unit) {
        const unitGrades = studentGrades.filter((grade) => grade.unit_id === unit.id);
        return unitGrades;
      }
    }
  
    return null;
  }
  // Function to add a lecture
  function addLecture(name) {
    const newLecture = new Lecture(lectures.length + 1, name);
    lectures.push(newLecture);
  }
  
  // Function to add a unit
  function addUnit(name, lecture_id) {
    const newUnit = new Unit(units.length + 1, name, lecture_id);
    units.push(newUnit);
  }
  
  // Function to add a grade
  function addGrade(student_id, unit_id, value) {
    const newGrade = new Grade(grades.length + 1, student_id, unit_id, value);
    grades.push(newGrade);
  }
  
  // Function to simulate login
  function login(email, password) {
    const user = students.find((student) => student.email === email && student.password === password);
    return user ? user : null;
  }
  
  // Example usage
  addStudent("John", "Doe", "john.doe@email.com", "password123");
  addStudent("Jane", "Doe", "jane.doe@email.com", "password456");
  addStudent("Bob", "Smith", "bob.smith@email.com", "password789");
  addStudent("Alice", "Johnson", "alice.johnson@email.com", "password101");
  addStudent("Charlie", "Brown", "charlie.brown@email.com", "password202");
  
  addLecture("Mathematics");
  addUnit("Algebra", 1);
  
  addGrade(1, 1, "A");
  addGrade(2, 1, "B");
  addGrade(3, 1, "C");
  addGrade(4, 1, "A");
  addGrade(5, 1, "B");
  
  // Example login
  const loggedInUser = login("john.doe@email.com", "password123");
  console.log(loggedInUser);
  
  

  