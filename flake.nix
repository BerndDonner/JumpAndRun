# run with:                nix develop
# see metadata with:       nix flake metadata
# debug with:              nix repl
#                          :lf .#
# check with:              nix flake check
# If you want to update a locked input to the latest version, you need to ask
# for it:                  nix flake lock --update-input nixpkgs
# show available packages: nix-env -qa
#                          nix search nixpkgs
# show nixos version:      nixos-version
# 

{
  description = "C++ Development with Nix 24.05";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-24.05";
  };

  outputs = { self, nixpkgs }: {
    devShells = {
      x86_64-linux.default  = self.buildDevShell "x86_64-linux";
      aarch64-linux.default = self.buildDevShell "aarch64-linux";
      x86_64-darwin.default = self.buildDevShell "x86_64-darwin";
    };
  } // {
    buildDevShell = system: let
      pkgs = import nixpkgs {
        inherit system;
        config = {
          qt.enable = true; # Enable Qt configuration globally
        };
      };
    in
      pkgs.mkShell {

        nativeBuildInputs = with pkgs; [
          cmake
          pkg-config
          qt6.qttools
          qt6.wrapQtAppsHook
          qt6.qtwayland
          gdb
          makeWrapper
          bashInteractive
        ];

        QT_PLUGIN_PATH = "${pkgs.qt6.qtgraphs}/lib";

        # # set the environment variables that Qt apps expect
        shellHook = ''
          bashdir=$(mktemp -d)
          makeWrapper "$(type -p bash)" "$bashdir/bash" "''${qtWrapperArgs[@]}"
          exec "$bashdir/bash"
        '';
      };
  };
}
