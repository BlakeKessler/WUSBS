# WUSBS Version Codes (documentation)

   None of the information in this file is directly relevant to general use of WUSBS.  

The Version Number for WUSBS itself is split into 3 sub-parts, separated by dashes ('-'); it is of the form "Release Code-Patch Code-Branch Code.  
  _This format is not checked for by WUSBS at any point._
  
* The **Release Code** increases by 1 for every stable release. It will always equal the number of previous stable releases.
* The **Patch Code** encodes information about stability. If it is two numbers long, that version is a _stable patch_. If it is three numbers long, it is a _development snapshot_; it is not intended for general use, and crashes and incorrect makefiles should be expected.  
  * It is suggested to always use the **most recent _stable_ patch** of whatever release you are using.  
* The **Branch Code** encodes information about compatibility. If the Branch Codes of two stable releases share any numbers,  backwards-compatiblility exists between those releases. The numbers in a branch code should always be in descending order.  
  * A WUSBS file that builds correctly with version _0-0.0-0_ may not build correctly using version _3-0.0-1_, but a WUSBS file that builds correctly with either of those versions would be built correctly using version _8-0.0-1.0_.  
    * DISCLAIMER: none of those versions exist yet, and all but _0-0.0-0_ will likely never exist.  
