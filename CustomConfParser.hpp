#ifndef CIRCULAR_BALANCING_BUFFER_CUSTOMCONFPARSER_HPP
#define CIRCULAR_BALANCING_BUFFER_CUSTOMCONFPARSER_HPP

#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <memory>
#include <vector>
#include <stack>

namespace util_lib
{

    class NodeBase
    {
    public:
        NodeBase() = default;
        virtual ~NodeBase() = default;
    };


    class Node
    {
    private:
        std::shared_ptr<Node> itsParent;
        std::vector<std::shared_ptr<Node>> itsChilds;

        std::string itsValue;

    public:
        Node() = default;
        explicit Node(std::string value) : itsValue(std::move(value)) {}
        ~Node() = default;

    };


    size_t
    indent_level(const std::string & line_str)
    {
        size_t res = line_str.find_first_not_of(' ');
        if (res != std::string::npos){
            return res;
        }
        else {
            return std::string::npos;
        }
    }

    class LevelMachine
    {
    private:
        Node itsCurrentNode;

    public:
        LevelMachine() {}
        ~LevelMachine() = default;

        void parse_line(const std::string & line)
        {
            const auto level = indent_level(line);
            if (level != std::string::npos){
                if (level == itsCurrentNode.level()){
                    auto child = itsCurrentNode.get_new_child();

                }
            }
            else {
                if (itsCurrentNode.level() == 0){

                }

            }


        }

    };


    void make_parse(const std::string & filename)
    {
        std::ifstream file(filename);

        if (!file){
            std::cerr << "Can't open the file: " + filename << std::endl;
        }
        else {
            LevelMachine level_machine;
            std::string line;

            while(std::getline(file, line)){
                level_machine.parse_line(line);
            }
        }

    }



}


#endif //CIRCULAR_BALANCING_BUFFER_CUSTOMCONFPARSER_HPP
