module M5
  class Color
    attr_accessor :r,:g,:b
    def initialize(r,g,b)
      @r,@g,@b = r,g,b
    end

    def to_i
      ((@r>>3)<<11) | ((@g>>2)<<5) | (@b>>3)
    end

    def self.BLUE
      Color.new(0,0,255)
    end

  end

  module Button
    BtnA = 0
    BtnB = 1
    BtnC = 2
  end

  module BtnA
    def self.is_pressed?
      Button::is_pressed?(Button::BtnA)
    end
  end

end
