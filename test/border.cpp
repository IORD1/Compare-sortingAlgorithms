#include <iostream>  // cout
#include <string>
#include <vector>

size_t get_longest_text(const std::vector<std::string>& lines)
{
    size_t ret = 0;
    for (auto& line : lines)
    {
        if (line.size() > ret)
        {
            ret = line.size();
        }
    }
    return ret;
}

void print_border_top_or_bottom_line(size_t longest_text)
{
    for (size_t i = 0; i < longest_text + 4; ++i)
    {
        std::cout << "*";
    }
    std::cout << "\n";
}

void print_second_top_or_second_bottom_line(size_t longest_text)
{
    std::cout << "*";
    for (size_t i = 0; i < longest_text + 2; ++i)
    {
        std::cout << " ";
    }
    std::cout << "*";
    std::cout << "\n";
}

void print_line(const std::string& text, size_t longest_text)
{
    std::cout << "*";
    std::cout << " ";
    std::cout << text;
    std::cout << std::string(longest_text + 1 - text.size(), ' ');
    std::cout << "*";
    std::cout << "\n";
}

void print_lines_with_border(const std::vector<std::string>& lines)
{
    size_t longest_text = get_longest_text(lines);
    print_border_top_or_bottom_line(longest_text);
    print_second_top_or_second_bottom_line(longest_text);
    for (auto& line : lines)
    {
        print_line(line, longest_text);
    }
    print_second_top_or_second_bottom_line(longest_text);
    print_border_top_or_bottom_line(longest_text);
}

int main()
{
    std::vector<std::string> lines{"Blah", "Foo foo", "Third line", "And so on and so forth"};
    print_lines_with_border(lines);
}

// Outputs:
//
//   **************************
//   *                        *
//   * Blah                   *
//   * Foo foo                *
//   * Third line             *
//   * And so on and so forth *
//   *                        *
//   **************************