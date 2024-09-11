#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <algorithm>

void renameFiles(const std::string &dirPath, const std::string &prefix, const std::string &separator, const std::string &filter)
{
    if (!std::filesystem::exists(dirPath) || !std::filesystem::is_directory(dirPath))
    {
        std::cerr << "Error: Directory does not exist or is not a directory." << std::endl;
        return;
    }

    std::vector<std::filesystem::path> files;
    for (const auto &entry : std::filesystem::directory_iterator(dirPath))
    {
        if (std::filesystem::is_regular_file(entry))
        {
            if (filter.empty() || entry.path().extension() == filter)
            {
                files.push_back(entry.path());
            }
        }
    }

    std::sort(files.begin(), files.end());

    int counter = 1;
    for (const auto &file : files)
    {
        std::string newName = prefix + separator + std::to_string(counter) + file.extension().string();
        std::filesystem::path newPath = file.parent_path() / newName;

        try
        {
            std::filesystem::rename(file, newPath);
            std::cout << "Renamed: " << file.filename() << " -> " << newName << std::endl;
            counter++;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error renaming " << file.filename() << ": " << e.what() << std::endl;
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <command>\n";
        return 1;
    }

    std::string command = argv[1];

    if (command == "massname")
    {
        if (argc < 5 || argc > 6)
        {
            std::cerr << "Usage: " << argv[0] << " massname <directory_path> <prefix> <separator> [extension_filter]" << std::endl;
            return 1;
        }

        std::string dirPath = argv[2];
        std::string prefix = argv[3];
        std::string separator = argv[4];
        std::string filter = (argc == 6) ? argv[5] : "";

        if (!filter.empty() && filter[0] != '.')
        {
            filter = "." + filter;
        }

        renameFiles(dirPath, prefix, separator, filter);
    }
    else if (command == "help")
    {
        std::cout << "Commands:\n"
                  << "massname - mass renaming system | Usage: " << argv[0] << " massname <directory_path> <prefix> <separator> [extension_filter]\n";
    }
    else
    {
        std::cerr << "Error: '" << command << "' is not a valid command. Type '" << argv[0] << " help' for more information.\n";
    }

    return 0;
}
