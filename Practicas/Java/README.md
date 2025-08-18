# ☕ Prácticas en Java

Esta carpeta contendrá las prácticas implementadas en Java.

## 🛠️ Configuración del Entorno

### Requisitos
- **JDK**: Java 11 o superior
- **Build Tool**: Maven o Gradle (opcional) para este curso nunca usaremos maven por default a menos que lo especifique. 
- **IDE Recomendado**: IntelliJ IDEA o Eclipse

### Compilación General
```bash
javac -d bin src/*.java
java -cp bin Main
```

## 📁 Prácticas

### 🔄 Pendientes
Las prácticas en Java se implementarán según se requiera en el curso.

## 📚 Convenciones de Código

- **Estilo**: Oracle Java Code Conventions
- **Naming**:
  - Classes/Interfaces: `PascalCase`
  - Methods/Variables: `camelCase`
  - Constants: `UPPER_SNAKE_CASE`
  - Packages: `lowercase`
- **Estructura de Paquetes**: `com.itam.eda.pr[x]`

## 🔧 Estructura Típica de Proyecto
```
PR[X]/
├── src/
│   └── main/
│       └── java/
│           └── com/itam/eda/pr[x]/
├── test/
├── resources/
├── pom.xml (si usa Maven)
└── README.md
```