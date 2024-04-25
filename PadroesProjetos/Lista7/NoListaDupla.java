public class NoListaDupla {
	private Integer info;
	private NoListaDupla ant;
	private NoListaDupla prox;
	
	public NoListaDupla(Integer info) {
		super();
		this.info = info;
		this.ant = null;
		this.prox = null;
	}
	
	public Integer getInfo() {
		return info;
	}
	public void setInfo(Integer info) {
		this.info = info;
	}
	public NoListaDupla getAnt() {
		return ant;
	}
	public void setAnt(NoListaDupla ant) {
		this.ant = ant;
	}
	public NoListaDupla getProx() {
		return prox;
	}
	public void setProx(NoListaDupla prox) {
		this.prox = prox;
	}
}