{
  pkgs ? import <nixpkgs> { },
}:

let
  mainPkg = if builtins.pathExists ./default.nix then pkgs.callPackage ./default.nix { } else { };
  pkgInputs =
    with pkgs;
    [
      clang
      julec
      julefmt
      juledoc
      curlMinimal
    ]
    ++ (mainPkg.nativeBuildInputs or [ ]);
in
pkgs.mkShell {
  packages = pkgInputs;

  shellHook = ''
    echo -ne "-----------------------------------\n "

    echo -n "${toString (map (pkg: "• ${pkg.name}\n") pkgInputs)}"

    echo "-----------------------------------"
  '';
}
