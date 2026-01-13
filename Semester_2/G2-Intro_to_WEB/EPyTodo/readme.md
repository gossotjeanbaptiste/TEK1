# EPYTODO

## Project Overview
EPYTODO is a backend-focused project to build a Todo List application using **Node.js** and **MySQL**. The application allows users to manage their tasks efficiently. A frontend implementation can be added as a bonus.

---

## Features
1. **MySQL Database**:
    - Database name: `epytodo`
    - Tables:
      - `user`: Stores user information.
      - `todo`: Stores tasks associated with users.

2. **Web Server**:
    - Built using **Node.js** and **Express**.
    - REST API for CRUD operations.
    - JWT-based authentication for protected routes.

3. **Environment Variables**:
    - `.env` file for configuration:
      - `MYSQL_DATABASE`, `MYSQL_HOST`, `MYSQL_USER`, `MYSQL_ROOT_PASSWORD`
      - `PORT`, `SECRET`

4. **Routes**:
    - User management: Register, login, view, update, and delete users.
    - Task management: Create, view, update, and delete tasks.

---

## Database Schema
### `user` Table
| Field       | Type         | Constraints                     |
|-------------|--------------|----------------------------------|
| `id`        | INT          | Primary Key, Auto Increment     |
| `email`     | VARCHAR(255) | Not Null, Unique                |
| `password`  | VARCHAR(255) | Not Null                        |
| `name`      | VARCHAR(255) | Not Null                        |
| `firstname` | VARCHAR(255) | Not Null                        |
| `created_at`| DATETIME     | Default: Current Timestamp      |

### `todo` Table
| Field        | Type         | Constraints                     |
|--------------|--------------|----------------------------------|
| `id`         | INT          | Primary Key, Auto Increment     |
| `title`      | VARCHAR(255) | Not Null                        |
| `description`| TEXT         | Not Null                        |
| `created_at` | DATETIME     | Default: Current Timestamp      |
| `due_time`   | DATETIME     | Not Null                        |
| `status`     | ENUM         | Default: `todo`                 |
| `user_id`    | INT          | Foreign Key (References `user`) |

---

## Repository Structure
```
|-- .env
|-- package.json
|-- src
     |-- config
     |   `-- db.js
     |-- index.js
     |-- middleware
     |   |-- auth.js
     |   `-- notFound.js
     |-- routes
          |-- auth
          |   `-- auth.js
          |-- todos
          |   |-- todos.js
          |   `-- todos.query.js
          `-- user
                |-- user.js
                `-- user.query.js
```

---

## API Endpoints
### Authentication
| Route       | Method | Protected | Description               |
|-------------|--------|-----------|---------------------------|
| `/register` | POST   | No        | Register a new user       |
| `/login`    | POST   | No        | Login a user              |

### User Management
| Route               | Method | Protected | Description               |
|---------------------|--------|-----------|---------------------------|
| `/user`             | GET    | Yes       | View all user information |
| `/user/todos`       | GET    | Yes       | View all user tasks       |
| `/users/:id`        | GET    | Yes       | View user by ID           |
| `/users/:id`        | PUT    | Yes       | Update user information   |
| `/users/:id`        | DELETE | Yes       | Delete user               |

### Task Management
| Route               | Method | Protected | Description               |
|---------------------|--------|-----------|---------------------------|
| `/todos`            | GET    | Yes       | View all tasks            |
| `/todos/:id`        | GET    | Yes       | View task by ID           |
| `/todos`            | POST   | Yes       | Create a new task         |
| `/todos/:id`        | PUT    | Yes       | Update a task             |
| `/todos/:id`        | DELETE | Yes       | Delete a task             |

---

## Error Handling
| Scenario                          | Response                              |
|-----------------------------------|---------------------------------------|
| User not logged in                | `{ "msg": "No token, authorization denied" }` |
| Invalid token                     | `{ "msg": "Token is not valid" }`    |
| Task or user not found            | `{ "msg": "Not found" }`             |
| Bad parameters                    | `{ "msg": "Bad parameter" }`         |
| Internal server error             | `{ "msg": "Internal server error" }` |

---

## Packages Used
- **Express**: Web framework.
- **mysql2**: MySQL database driver.
- **dotenv**: Environment variable management.
- **jsonwebtoken**: JWT for authentication.
- **bcryptjs**: Password hashing.
- **body-parser** (optional): Request body parsing.

---

## Notes
- Passwords must be hashed before storing in the database.
- Ensure proper HTTP status codes for all responses.
- Use a `.gitignore` file to exclude `node_modules` and sensitive files.

---  