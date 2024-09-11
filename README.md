# File Renamer

This C++ program provides a command-line utility for batch renaming files in a specified directory. It allows users to rename files with a custom prefix, separator, and optional extension filter.

## Features

- Mass rename files in a directory
- Custom prefix and separator for new filenames
- Optional file extension filter
- Preserves original file extensions
- Sorts files alphabetically before renaming
- Provides informative console output

## Requirements

- C++17 compatible compiler
- Standard C++ libraries

## Usage

### Compile the program

```bash
g++ -std=c++17 file_renamer.cpp -o file_renamer
```

### Run the program

The program supports two commands: `massname` and `help`.

#### Mass Rename Files

```bash
./file_renamer massname <directory_path> <prefix> <separator> [extension_filter]
```

- `<directory_path>`: Path to the directory containing files to rename
- `<prefix>`: Prefix for the new filenames
- `<separator>`: Separator between the prefix and file number
- `[extension_filter]`: (Optional) Filter files by extension (e.g., ".txt", ".jpg")

Example:
```bash
./file_renamer massname ./my_photos vacation_ - .jpg
```
This will rename all .jpg files in the `./my_photos` directory to `vacation_1.jpg`, `vacation_2.jpg`, etc.

#### Help

```bash
./file_renamer help
```
Displays usage information for the program.

## How It Works

1. The program checks if the specified directory exists.
2. It collects all files in the directory, applying the extension filter if provided.
3. Files are sorted alphabetically.
4. Each file is renamed using the format: `<prefix><separator><number><original_extension>`.
5. The program outputs the old and new filename for each renamed file.
6. If any errors occur during renaming, they are reported to the console.

## Error Handling

- Invalid directory paths are detected and reported.
- File renaming errors are caught and displayed without halting the program.
- Incorrect usage of the program results in helpful error messages.

## Limitations

- The program does not recursively rename files in subdirectories.
- It does not handle duplicate filenames that may result from the renaming process.

## Contributing

Feel free to fork this project and submit pull requests with improvements or bug fixes.

## License

[Specify your chosen license here]
