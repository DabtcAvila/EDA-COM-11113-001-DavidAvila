# 🐍 Prácticas en Python

Esta carpeta contendrá las prácticas implementadas en Python.

## 🛠️ Configuración del Entorno

### Requisitos
- **Python**: 3.8 o superior
- **pip**: Para gestión de paquetes
- **Entorno Virtual**: Recomendado usar `venv`

### Setup del Entorno
```bash
python3 -m venv venv
source venv/bin/activate  # En Windows: venv\Scripts\activate
pip install -r requirements.txt
```

### Ejecución General
```bash
python main.py
```

## 📁 Prácticas

### 🔄 Pendientes
Las prácticas en Python se implementarán según se requiera en el curso.

## 📚 Convenciones de Código

- **Estilo**: PEP 8
- **Naming**:
  - Classes: `PascalCase`
  - Functions/Variables: `snake_case`
  - Constants: `UPPER_SNAKE_CASE`
  - Private: `_leading_underscore`
- **Type Hints**: Usar cuando sea posible (Python 3.5+)
- **Docstrings**: Formato Google o NumPy

## 🔧 Estructura Típica de Proyecto
```
PR[X]/
├── src/
│   ├── __init__.py
│   ├── main.py
│   └── modules/
├── tests/
├── data/
├── docs/
├── requirements.txt
└── README.md
```

## 📦 Librerías Útiles
- **NumPy**: Arrays y operaciones numéricas
- **Matplotlib**: Visualización y gráficas
- **NetworkX**: Grafos y redes
- **heapq**: Heap nativo de Python