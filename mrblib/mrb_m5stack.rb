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

end
