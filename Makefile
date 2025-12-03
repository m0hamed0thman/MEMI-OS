# 1. تعريف المتغيرات
CXX = g++
SRC_DIR = src
# لو حبيت تغير المسار مستقبلاً بتغيره هنا بس
PROJECT_DIR = /home/mohamed-othman/CLionProjects/MIME_OS

# 2. تجميع كل ملفات الـ Source
# (لاحظ اننا بنستخدم مسارات نسبية من داخل فولدر المشروع)
SOURCES = $(PROJECT_DIR)/src/main.cpp \
          $(PROJECT_DIR)/src/kernel/logging/Logger.cpp \
          $(PROJECT_DIR)/src/utils/StringUtils.cpp \
          $(PROJECT_DIR)/src/shell/Shell.cpp \
          $(PROJECT_DIR)/src/shell/Commands.cpp \
          $(PROJECT_DIR)/src/kernel/filesystem/File.cpp \
          $(PROJECT_DIR)/src/kernel/filesystem/Directory.cpp \
          $(PROJECT_DIR)/src/kernel/filesystem/FileSystem.cpp

# 3. اسم البرنامج النهائي
OUTPUT = mime-os

# 4. أمر البناء
buildshell:
	$(CXX) $(SOURCES) -o $(OUTPUT)

# 5. أمر التنظيف (اختياري)
clean:
	rm -f $(OUTPUT)