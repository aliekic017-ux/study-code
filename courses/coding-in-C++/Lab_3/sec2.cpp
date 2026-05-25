#include <iostream>
#include <string>
#include <vector>

class Content
{
private:
    std::string type;
    std::string title;

public:
    Content(const std::string& type,
            const std::string& title)
    {
        this->type = type;
        this->title = title;
    }

    void displayContent() const
    {
        std::cout << "Content: "
                  << title
                  << " ("
                  << type
                  << ")"
                  << std::endl;
    }
};

class Lesson
{
private:
    std::string title;

    // Komposition:
    // Lesson besitzt Content stark
    std::vector<Content> contents;

public:
    Lesson(const std::string& title)
    {
        this->title = title;
    }

    void addContent(const Content& content)
    {
        contents.push_back(content);
    }

    void showLesson() const
    {
        std::cout << "Lesson: "
                  << title
                  << std::endl;

        for (const Content& c : contents)
        {
            c.displayContent();
        }
    }
};

class Course
{
private:
    std::string title;
    std::string description;

    // Komposition:
    // Course besitzt Lessons
    std::vector<Lesson> lessons;

public:
    Course(const std::string& title,
           const std::string& description)
    {
        this->title = title;
        this->description = description;
    }

    void addLesson(const Lesson& lesson)
    {
        lessons.push_back(lesson);
    }

    void showCourse() const
    {
        std::cout << "Course: "
                  << title
                  << std::endl;

        std::cout << description
                  << std::endl;

        for (const Lesson& l : lessons)
        {
            l.showLesson();
        }
    }
};

class User
{
private:
    std::string name;

    // Assoziation:
    // User kennt Kurse
    std::vector<Course*> enrolledCourses;

public:
    User(const std::string& name)
    {
        this->name = name;
    }

    void enroll(Course* course)
    {
        enrolledCourses.push_back(course);
    }

    void showUser() const
    {
        std::cout << "User: "
                  << name
                  << std::endl;
    }
};

class Platform
{
private:

    // Komposition:
    // Platform besitzt Courses
    std::vector<Course> courses;

    // Aggregation:
    // Platform kennt User
    std::vector<User*> users;

public:
    void addCourse(const Course& course)
    {
        courses.push_back(course);
    }

    void registerUser(User* user)
    {
        users.push_back(user);
    }
};

int main()
{
    Platform moodle;

    Course cpp("C++ Course",
               "Introduction to OOP");

    Lesson lesson1("Classes");

    Content video("Video",
                  "OOP Basics");

    lesson1.addContent(video);

    cpp.addLesson(lesson1);

    User ali("Ali");

    ali.enroll(&cpp);

    moodle.addCourse(cpp);

    moodle.registerUser(&ali);

    cpp.showCourse();

    return 0;
}