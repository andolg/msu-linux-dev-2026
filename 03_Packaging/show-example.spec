Name:           show-example
Version:        0.1
Release:        alt1
Summary:        Text file viewer
License:        MIT
Group:          Other
Source:         %{name}-%{version}.tar.gz

BuildRequires:  gcc make libncursesw-devel

%description
A terminal text file viewer using ncurses.
Press Space to scroll and Escape to exit.

%prep
%setup

%build
make

%install
make install DESTDIR="%buildroot" BINDIR="%_bindir"

%files
%_bindir/Show