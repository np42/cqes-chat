import { Bus }             from 'cqes';
import { Gateway, Config } from 'cqes-gw-http';

export default new class extends Gateway {

  public init(config: Config, bus: Bus) {
    super.init(config, bus);
    
  }

}
