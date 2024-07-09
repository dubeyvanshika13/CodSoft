#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class TodoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& task) {
        tasks.emplace_back(task);
    }

    void markTaskCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
        }
    }

    void removeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks.erase(tasks.begin() + index);
        }
    }

    void displayTasks(sf::RenderWindow& window, sf::Font& font) {
        window.clear(sf::Color::White);
        int y = 50;
        for (int i = 0; i < tasks.size(); ++i) {
            sf::Text text;
            text.setFont(font);
            text.setCharacterSize(24);
            text.setFillColor(sf::Color::Black);
            text.setPosition(50, y);
            if (tasks[i].completed) {
                text.setString("[X] " + tasks[i].description);
            } else {
                text.setString("[ ] " + tasks[i].description);
            }
            window.draw(text);
            y += 30;
        }
        window.display();
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "To-Do List");
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font\n";
        return 1;
    }

    TodoList todoList;
    std::string currentTask;
    sf::Text inputText;
    inputText.setFont(font);
    inputText.setCharacterSize(24);
    inputText.setFillColor(sf::Color::Black);
    inputText.setPosition(50, 10);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == '\b' && !currentTask.empty()) {
                    currentTask.pop_back();
                } else if (event.text.unicode == '\r') {
                    todoList.addTask(currentTask);
                    currentTask.clear();
                } else if (event.text.unicode < 128 && event.text.unicode != '\b') {
                    currentTask += static_cast<char>(event.text.unicode);
                }
            } else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Num1) {
                    todoList.markTaskCompleted(0);
                } else if (event.key.code == sf::Keyboard::Num2) {
                    todoList.markTaskCompleted(1);
                } else if (event.key.code == sf::Keyboard::Num3) {
                    todoList.markTaskCompleted(2);
                } else if (event.key.code == sf::Keyboard::Delete) {
                    if (!currentTask.empty() && std::isdigit(currentTask[0])) {
                        int index = currentTask[0] - '1';
                        todoList.removeTask(index);
                    }
                }
            }
        }

        inputText.setString("New Task: " + currentTask);
        window.clear(sf::Color::White);
        window.draw(inputText);
        todoList.displayTasks(window, font);
    }

    return 0;
}
