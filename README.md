# In early development stage

# FRSGUI 
Framework for Rapid and Simple development of General User Interface applications, based on SFML.


# Objectives

Task priority: 
  - ~~Stardarise the naming convention for functions and variables~~
  - ~~Add FONT as a styling option, defualt font, functions to change default font, folder for default font in the FRSGUI dir~~
  - ~~Add Text element to UI_element class, create public getters. Standardize the draw fuction for Text and Elements~~
  - ~~Rebuilding the style system to <unordered_map> with <variant> instead of variables on top of variables (making the system scalable and easy to add new styles)~~
  - ~~CHANGE THE PASSES BY CONST REFERENCE TO PASS BY VALUE WHEN USING SIMPLE DATATYPES YOU DONKEY!!!!! (ref/ptr = 8 bytes, uint32 = 4bytes nice brain nice)~~
  - ~~Custom UI_elements~~
  - ~~Create a builder class~~
  - Style based layout
      - add window/screen as a base ui_element
      - each element must be a child of some element
      - add layouts like, center, left, right, top, bottom
      - margin, padding
      - height, width
  - other Styling options
      - Add labels that can be tied to elements
      - Add placeholder for inputs (default text if no user data is inputed)
      - add an ability to create smooth edges to elements (css border-radius type shii)
      - hover styling (effect on mouse over the element)
  - Create hard-coded UI_elements: 
      - ~~Button~~
      - Input: 
          - ~~Textarea~~ 
          - ~~Number inputs~~
          - ~~Checkbox~~
          - Radio checkbox?
      - Slider
          - numbers slider
          - custom sliders
      - ~~Text block~~
  - ~~Custom styling to these new elements~~
  - ~~Custom handler functions for elements~~ 

   - ~~Refactor rendering~~
   - Code optimalization

  - Future, shallow ideas:
    - Dynamic interaction with elements? (drag and drop, resize by mouse)
   
# Naming convention
  - FRSGUI namespace: `fr`
  - Variables: `snake_case`
  - Classes: `PascalCase`
  - Files: `PascalCase`
  - Folders: `snake_case`
  - Abbreviations: `CL(capital letters)`
  - Functions: `camelCase`
  - Constructor wrapper functions: `PascalCase | (same name as the constructor class)`
  
