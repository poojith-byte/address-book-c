# address-book-c
Features

- **Full CRUD Operations**: Create, Read, Update, and Delete contacts.
- **Smart Search**: Search for contacts via Name, Phone Number, or Email.
- **Data Validation**:
  - **Phone**: Ensures 10-digit numbers starting with valid prefixes (6-9).
  - **Email**: Validates format (e.g., `user@domain.com`) and checks for supported domains (Gmail, Outlook, Yahoo).
  - **Name**: Enforces length and spacing rules.
- **Persistence**: Automatically saves data to `contacts.txt` so your information is never lost.
- **Conflict Management**: Prevents duplicate phone numbers and emails to ensure data integrity.

## 🏗 Industrial Pipeline (CI/CD)

This project uses **GitHub Actions** to simulate a professional development environment.
- **Automated Build**: Every `git push` triggers a Linux-based virtual machine to compile the code using `gcc`.
- **Environment**: Tested on `ubuntu-latest`.
- **Validation**: Ensures the project is always in a "working state" before it reaches the main branch.

## 🛠 Installation & Usage

### Prerequisites
- A C compiler (GCC)
- Linux/WSL environment (Recommended)
