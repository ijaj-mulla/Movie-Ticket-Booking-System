# 🎟️ Movie Ticket Booking System

## 📌 Project Overview
The **Movie Ticket Booking System** is a **console-based C++ application** that allows admins to add movie details and customers to book tickets. It uses **file handling** to store movie and customer details and incorporates **text-to-speech functionality (eSpeak)** for an interactive user experience.

## 📂 Features

### 🎬 Admin Features
- Add new movies with details like name, available tickets, and price.
- View the list of customers who have booked tickets.
- Stores movie details in `admin.txt` and customer details in `customer.txt`.

### 🧑‍💼 Customer Features
- Book movie tickets by entering name, movie title, and mobile number.
- Check available movies and their details.
- Stores booking information in `customer.txt`.

### 🔊 Additional Features
- **Text-to-speech integration** using `eSpeak` for improved accessibility.
- **Loading animations** for a better user experience.

## 🛠️ Technologies Used
- **C++** (Core Programming)
- **File Handling** (`fstream` for storing data)
- **eSpeak** (Text-to-Speech feature)

## 📜 File Structure
```
📂 Movie Ticket Booking System
│── 📄 main.cpp         # Main source code file
│── 📄 admin.txt        # Stores movie details
│── 📄 customer.txt     # Stores customer bookings
│── 📄 README.md        # Project documentation
```

## 🚀 How to Run
1. **Install eSpeak** (if not installed) for the text-to-speech feature:
   ```bash
   sudo apt install espeak   # For Linux
   winget install espeak     # For Windows
   ```
2. **Compile the code** using a C++ compiler:
   ```bash
   g++ main.cpp -o movie_booking
   ```
3. **Run the program**:
   ```bash
   ./movie_booking
   ```

## 🤝 Contribution
Feel free to contribute to this project! You can report issues, suggest improvements, or create pull requests.

## 📜 License
This project is **open-source** and available under the MIT License.
