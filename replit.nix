{ pkgs }: {
	deps = [
		pkgs.rubyPackages.cocoapods
  pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}