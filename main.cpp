#include <iostream>
#include <vector>
#include <memory>
#include "Circle.h"

int main()
{
  
    Point::setMaxCoord(1920.0);

    std::vector<std::unique_ptr<Shape>> shapes;

    try 
    {
        Point center1(100, 100);
        Point onCircle1(200, 100);
        shapes.push_back(std::make_unique<Circle>(center1, onCircle1));

        shapes.push_back(std::make_unique<Circle>(400, 300, 400, 500));

        std::string input = "600 450 750 450";
        std::stringstream ss(input);
        auto circleFromStream = std::make_unique<Circle>();
        ss >> *circleFromStream;
        shapes.push_back(std::move(circleFromStream));

        for (const auto& shape : shapes)
        {
            std::cout << *shape << std::endl;
        }
    }
    catch (const std::exception& ex) 
    {
        std::cerr << "Error: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}
