# Football Group Division Management App

This console application helps manage football group divisions, including creating divisions, adding teams, managing games, viewing standings, and updating team information.

## Technical Details

This project uses C++ and leverages the following for input handling and data storage:

### 1.`cin.ignore(numeric_limits<std::streamsize>::max(), '\n')` for Input Buffer Management

**Purpose:** This line clears the input buffer, discarding leftover characters, including the newline (`\n`) often left behind after user input.

**Why It's Important:** It prevents issues when mixing `cin >> ...` (formatted input) and `getline()` (reading entire lines), ensuring that `getline()` doesn't read a leftover newline by mistake.

**Input Validation:** The functions `getIntegerInput()` and `getStringInput()` are used to ensure that the user enters valid data. They handle potential errors and clear the input buffer properly.

### 2.`json.hpp` from nlohmann for JSON Data Handling

**Purpose:** The `json.hpp` header-only library from nlohmann (\[[URL json hpp ON nlohmann.github.io](https://nlohmann.github.io/json/)) is used to work with JSON data for storing and retrieving application data.

**Why `json.hpp`?**

*   **Ease of Use:** Simple and intuitive API for handling JSON in C++.
*   **Header-Only:** Easy integration – just include `json.hpp`.
*   **Standard Compliance:** Compliant with the latest JSON standard.
*   **Intuitive Syntax:** Allows working with JSON similar to standard C++ containers.

**How It's Used:** This project uses `json.hpp` to serialize (convert) C++ data structures (teams, divisions) into JSON format for saving to a file (e.g., `teams.json`) and to deserialize (parse) JSON data from a file back into C++ objects when loading.

## Current Features

*   **Manage Teams:**
    *   **Register Teams:** Allows registration of new teams with input validation to ensure correct data types and non-empty team names. Data is saved in JSON format.
    *   **Unregister Teams:** (Not yet fully implemented)
    *   **Update Teams:** (Not yet fully implemented)
*   **Manage Games:** (Not yet implemented)
*   **View Standings:** (Not yet implemented)
*   **Main Menu:** Provides a text-based menu to navigate between the different features.
*   **Input Validation:** Ensures the user enters valid data and provides error messages when needed.

## Future Improvements

*   Implement "Unregister Teams" functionality.
*   Implement "Update Teams" functionality.
*   Implement "Manage Games" features (schedule generation, result entry).
*   Implement "View Standings" feature (calculate and display standings).
*   Add more robust error handling.
*   Consider using a more comprehensive data storage mechanism (e.g., a database) for larger datasets.