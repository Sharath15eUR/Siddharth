#!/bin/bash

# Log file for errors
ERROR_LOG="errors.log"

# Recursive function to search for keyword in directory and subdirectories
search_directory() {
    local dir="$1"
    local keyword="$2"
    
    for file in "$dir"/*; do
        if [ -d "$file" ]; then
            search_directory "$file" "$keyword" # Recursive call for subdirectories
        elif [ -f "$file" ]; then
            if grep -q "$keyword" "$file" 2>> "$ERROR_LOG"; then
                echo "Match found in: $file"
            fi
        fi
    done
}

# Display help menu using Here Document
show_help() {
    cat << EOF
Usage: $0 [OPTIONS]
Options:
  -d <directory>  Search recursively for a keyword in a directory.
  -k <keyword>    Keyword to search for.
  -f <file>       Search for a keyword in a specific file.
  --help          Show this help message.

Example Usage:
  $0 -d logs -k error
  $0 -f script.sh -k TODO
  $0 --help
EOF
}

# Error handling and redirection
handle_error() {
    echo "Error: $1" | tee -a "$ERROR_LOG"
    exit 1
}

# Validate inputs using Regular Expressions
validate_inputs() {
    if [[ -n "$file" && ! -f "$file" ]]; then
        handle_error "File '$file' does not exist."
    fi
    if [[ -n "$dir" && ! -d "$dir" ]]; then
        handle_error "Directory '$dir' does not exist."
    fi
    if [[ -z "$keyword" ]]; then
        handle_error "Keyword cannot be empty."
    fi
}

# Process command-line arguments using getopts
while getopts ":d:k:f:-:" opt; do
    case "$opt" in
        d) dir="$OPTARG" ;;
        k) keyword="$OPTARG" ;;
        f) file="$OPTARG" ;;
        -) 
            case "$OPTARG" in
                help) show_help; exit 0 ;;
                *) handle_error "Invalid option: --$OPTARG" ;;
            esac
            ;;
        ?) handle_error "Invalid option: -$OPTARG" ;;
    esac
done

# Display script metadata using special parameters
echo "Running script: $0"
echo "Total arguments: $#"
echo "Arguments received: $@"

echo "Checking inputs..."
validate_inputs

echo "Processing..."

# Execute search based on arguments
if [[ -n "$dir" && -n "$keyword" ]]; then
    search_directory "$dir" "$keyword"
elif [[ -n "$file" && -n "$keyword" ]]; then
    if grep -q "$keyword" "$file" 2>> "$ERROR_LOG"; then
        echo "Match found in file: $file"
    else
        echo "No match found in file: $file"
    fi
else
    handle_error "Invalid usage. Use --help for correct syntax."
fi

# Display exit status
echo "Exit status: $?"
