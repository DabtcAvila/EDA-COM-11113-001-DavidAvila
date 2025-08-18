# My Java Project

This is a simple Java project that demonstrates how to set up a Java application using Maven. Hello world.

## Project Structure

```
my-java-project
├── src
│   └── main
│       └── java
│           └── App.java
├── pom.xml
└── README.md
```

## Prerequisites

- Java Development Kit (JDK) 8 or higher
- Apache Maven

## Building the Project

To build the project, navigate to the project directory and run the following command:

```
mvn clean install
```

## Running the Application

After building the project, you can run the application using the following command:

```
mvn exec:java -Dexec.mainClass="App"
```

## License

This project is licensed under the MIT License.