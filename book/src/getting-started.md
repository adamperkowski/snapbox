# Getting Started
To get started with snapbox, you need to install the library first. You can do this by either:

Downloading the latest release package from the [releases page], extracting it and placing it in your project's directory:
```bash
tar -xzf snapbox-0.1.0.tar.gz
rm snapbox-0.1.0.tar.gz
```

Or cloning the repository into a Git submodule:
```bash
git submodule add https://github.com/adamperkowski/snapbox.git snapbox
git submodule update --init
# you can also specify a tag to get a specific version:
cd snapbox
git checkout v0.1.0
cd ..
```

After you have the library installed in your project, you can start using it by including it in your code:
```jule
use "snapbox"
```

[releases page]: https://github.com/adamperkowski/snapbox/releases
