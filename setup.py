from distutils.core import setup, Extension

def main():
    setup(name="libc",
          version="1.0.0",
          description="Test c-api library for python",
          author="Ilya Zhukov",
          author_email="izhukov1992@gmail.com",
          ext_modules=[Extension("libc", ["libc/libc.c"])])

if __name__ == "__main__":
    main()