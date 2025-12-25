# === Имя итогового исполняемого файла ===
TARGET = GameCLI.exe

# === Компилятор и флаги ===
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude


# === Папки ===
SRC_DIR = src
APP_DIR = app
OBJ_DIR = build

# === Все исходники (.cpp) ===
SRCS = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(APP_DIR)/*.cpp)

# === Преобразуем их в объектники (.o) ===
OBJS = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(notdir $(SRCS)))

# === Правило по умолчанию ===
all: $(TARGET)

# === Линковка ===
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@

# === Компиляция исходников из src/ ===
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# === Компиляция исходников из app/ ===
$(OBJ_DIR)/%.o: $(APP_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# === Создание каталога для объектных файлов ===
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# === Очистка сборки ===
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# === Полная пересборка ===
rebuild: clean all

.PHONY: all clean rebuild
