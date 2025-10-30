{
  pkgs ? import <nixpkgs> { },
}:

let
  pkgInputs = with pkgs; [
    clang
    julec
    julefmt
    juledoc
    curlMinimal
  ];
in
pkgs.mkShell {
  packages = pkgInputs;

  shellHook = ''
    echo -ne "-----------------------------------\n "

    echo -n "${toString (map (pkg: "• ${pkg.name}\n") pkgInputs)}"

    echo "-----------------------------------"
  '';
}
