# Restaurant Management System

## Project Overview
This C++ project implements a restaurant management system designed to help restaurant staff efficiently handle table assignments, reservations, and waitlists. The system allows users to manage parties waiting for tables, track table availability, and optimize seating arrangements based on party size and table capacity.

## Key Features
- **Waitlist Management**: Add parties to a waitlist with their name, party size, and contact information
- **Table Layout Management**: Configure and manage the restaurant's table layout, including seat counts and occupancy status
- **Seating System**: Seat parties from the waitlist at available tables based on party size
- **Table Clearing**: Mark tables as available when parties leave
- **Status Visualization**: View the current waitlist and status of all tables in the restaurant
- **Data Persistence**: Store all information in text files to ensure data is preserved between program runs

## Data Structures Used
- **Maps**: Used to manage the restaurant layout, enabling efficient lookup, addition, and update of table statuses
- **Lists**: Implemented for waitlist management, allowing dynamic addition and removal of parties
- **File I/O**: Used for reading from and writing to the layout and guest information files, providing data persistence

## File Formats
The system uses two main files to store data:

### Restaurant Layout (layout.txt)
This file stores information about each table in the restaurant, including:
- Table number
- Number of seats
- Name of occupying party (or "null" if unoccupied)

Format: `table_number,seats,occupant_name`

Example:
```
1,3,null
2,2,null
3,6,null
4,2,null
5,4,null
```

### Guest Waitlist (guest_info.txt)
This file stores information about each party on the waitlist, including:
- Party name
- Number of people in the party
- Contact information

Format: `name,party_size,contact_info`

Example:
```
Jake,3,8123123
Martha,1,12312
Sonya,4,312312
```

## Compilation and Usage
To compile the program:
```bash
g++ -o restaurant Restaurant.cpp
```

To run the program:
```bash
./restaurant
```

## User Interface
Upon running the program, you will be presented with a menu of options:
1. Add a party to the waitlist
2. View the current waitlist
3. View table status
4. Seat a party
5. Clear a table
6. Exit

Follow the prompts to navigate through the system and manage your restaurant efficiently.

## Project Structure
```
Reservation-Project/
├── Restaurant.cpp       # Main source code
├── layout.txt           # Table layout configuration
├── guest_info.txt       # Waitlist information
├── README.md            # This file
└── .gitignore           # Git ignore rules
```

