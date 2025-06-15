# Building a custom archiver `crtar` with file extension `.crt`

## 1. Plan

Create a simple archiver a that can be used to archive files with a `.crt` extension.

Idea was to replicate the functionality of `tar` but with a custom file extension.

### 1.1. What `tar` does

It's a GNU tool that creates an archive of files and directories, preserving their structure, file names, permissions, and other metadata.

### 1.2. What `crtar` should do

- Take multiple files and directories as input.
- Write them to a single archive file with a `.crt` extension.
- Preserve the directory structure, file names, permissions, and other metadata.
- Support basic operations like listing contents, extracting files, and creating archives.

## 2. Implementation
