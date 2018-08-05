<menu>
  <category each={cat, c in categories} cat={cat}></category>

  <script>
    this.categories = [
      {title: 'characters', items: ['alfred', 'vianney','karine']},
      {title: 'events', items: ['start', 'craft','love']}
    ]
  </script>
</menu>

<category>
  <h3>{opts.cat.title}</h3>
  <ul class="demo-list-icon mdl-list">
    <li class="mdl-list__item" each={item, i in opts.cat.items}>
      <span class="mdl-list__item-primary-content">
          <i class="material-icons mdl-list__item-icon">person</i>
          {item}
      </span>
    </li>
  </ul>
</category>
