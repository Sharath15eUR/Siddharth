#!/bin/bash

# Ensure correct number of arguments
if [ "$#" -ne 3 ]; then
    echo "Usage: $0 <source_directory> <backup_directory> <file_extension>"
    exit 1
fi

# Assign arguments to variables
SOURCE_DIR="$1"
BACKUP_DIR="$2"
FILE_EXT="$3"

# Check if source directory exists
if [ ! -d "$SOURCE_DIR" ]; then
    echo "Error: Source directory does not exist."
    exit 1
fi

# Create backup directory if it does not exist
if [ ! -d "$BACKUP_DIR" ]; then
    mkdir -p "$BACKUP_DIR" || { echo "Error: Failed to create backup directory."; exit 1; }
fi

# Find files matching the extension and store in an array
mapfile -t FILES < <(find "$SOURCE_DIR" -maxdepth 1 -type f -name "*${FILE_EXT}")

# Check if there are files to back up
if [ "${#FILES[@]}" -eq 0 ]; then
    echo "No files found with extension $FILE_EXT in $SOURCE_DIR."
    exit 1
fi

# Initialize backup count and total size
BACKUP_COUNT=0
TOTAL_SIZE=0
export BACKUP_COUNT

# Process files
for FILE in "${FILES[@]}"; do
    FILE_NAME=$(basename "$FILE")
    DEST_FILE="$BACKUP_DIR/$FILE_NAME"

    # Get file size
    FILE_SIZE=$(stat -c %s "$FILE")
    echo "Backing up: $FILE_NAME ($FILE_SIZE bytes)"

    # Check if file exists in backup directory and compare timestamps
    if [ -f "$DEST_FILE" ]; then
        if [ "$FILE" -nt "$DEST_FILE" ]; then
            cp "$FILE" "$DEST_FILE"
            echo "Updated: $FILE_NAME"
        else
            echo "Skipped (Already up-to-date): $FILE_NAME"
        fi
    else
        cp "$FILE" "$DEST_FILE"
        echo "Copied: $FILE_NAME"
    fi

    ((BACKUP_COUNT++))
    ((TOTAL_SIZE+=FILE_SIZE))

done

# Generate backup report
REPORT_FILE="$BACKUP_DIR/backup_report.log"
echo "Backup Summary:" > "$REPORT_FILE"
echo "Total files processed: $BACKUP_COUNT" >> "$REPORT_FILE"
echo "Total size of files backed up: $TOTAL_SIZE bytes" >> "$REPORT_FILE"
echo "Backup location: $BACKUP_DIR" >> "$REPORT_FILE"

echo "Backup completed. Report saved at: $REPORT_FILE"
